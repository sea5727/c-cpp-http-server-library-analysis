# HTTPS Server

## Create Openssl Certificate

1. private key 생성 
먼저 private key를 생성한다.
```
openssl genrsa -out private.key 2048
```

2. public key 생성
그후 private key와 대칭되는 public key를 생성한다.
```
openssl rsa -in private.key -pubout -out public.key
```

3. csr 파일 생성
CSR 이란 Cerficate Signing Reuqest로 CA(인증 기관)에 인증을 요청하는 형식 데이터이다.

아래의 정보를 작성한다.
- Country Name (2 letter code)
- State or Province Name (full name)
- Locality Name (eg, city) [Default City]
- Organization Name (eg, company) [Default Company Ltd]
- Organizational Unit Name (eg, section)
- Common Name (eg, your name or your server's hostname)
- Email Address

```
openssl req -new -key private.key -out private.csr
```


nginx 나 apache server 등을 사용하여 CA에 요청해야하는경우
csr 파일을 사용하면 된다.

4. crt 파일 생성
서명을 한다. ( CA 에서 받거나, 직접 할 수 있다.)

직접하는 경우 커맨드는 아래와 같다.
```
openssl req -x509 -days 365 -key private.key -in private.csr -out mycommoncrt.crt 
```

5. 설정파일로 생성
csr 파일과 crt 파일을 만들기위해 매번 정보를 입력해야하는데
config 파일로 해결 할 수 있다.

```ini
[req]
default_bits = 2048
prompt = no
default_md = sha256
req_extensions = req_ext
distinguished_name = dn

[ dn ]
C=KR #Country Name (2 letter code)
ST=seoul #State or Province Name (full name)
L=seoul #Locality Name (eg, city) [Default City]
O= #Organization Name (eg, company) [Default Company Ltd]
OU= #Organizational Unit Name (eg, section)
CN=test #Common Name (eg, your name or your server's hostname)
emailAddress= #Email Address


[ req_ext ]
basicConstraints = CA:FALSE
keyUsage = nonRepudiation, digitalSignature, keyEncipherment
subjectAltName = @alt_names

[ alt_names ]
DNS.0 = www.dmkd.dp.ua
DNS.1 = dmkd.dp.ua
```

```
openssl req -new -key private.key -out private.csr -config ssl.conf
openssl req -x509 -days 365 -key private.key -in private.csr -out mycommoncrt.crt -config ssl.conf -extensions req_ext
```


## 추가 내용

Subject Alternative Name : 인증서와 도메인 또는 IP와 매핑하는 정보이다.
https를 ip로 접속하려면 오류를 뱉을 때가 있다. 그때 SAN에 ip정보를 추가해야한다.

``` ini
[ alt_names ]
DNS.0 = www.dmkd.dp.ua
DNS.1 = dmkd.dp.ua
IP.0 = 192.168.0.35
IP.1 = 192.168.0.37
```


## Https Client

### Curl
```
$ curl --insecure -X GET https://192.168.0.36:18080
$ Hello world!
```

### Golang
```go
package main

import (
	"crypto/tls"
	"fmt"
	"io/ioutil"
	"net/http"
)

func main() {
	fmt.Println("Hello World")

	tr := &http.Transport{
		TLSClientConfig: &tls.Config{InsecureSkipVerify: true},
	}

	client := http.Client{Transport: tr}

	res, err := client.Get("https://192.168.0.36:18080")
	if err != nil {
		panic(err)
	}
	defer res.Body.Close()

	data, err := ioutil.ReadAll(res.Body)
	if err != nil {
		panic(err)
	}

	fmt.Printf("%s\n", data)

}

$ go run main.go
$ Hello world!
```

### Python
```python
import requests
import urllib3

if __name__ == "__main__":
    urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)

    r = requests.get('https://192.168.0.36:18080', verify=False)

    print(r.content)

$ python main.py
$ Hello world!

```
