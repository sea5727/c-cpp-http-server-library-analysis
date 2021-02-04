# c-cpp-http-server-library-analysis 


1. [cpprestsdk](https://github.com/microsoft/cpprestsdk)
-   stars 6k
-   cross platform 
-   http client/server, json, 비동기, websocket
-   difficult ( based [boost asio](https://www.boost.org/doc/libs/1_75_0/doc/html/boost_asio.html) )
-   linux performance issue
-   mininnum g++ 4.8, libboost:1.58

2. [crow](https://github.com/ipkn/crow)
-   stars 6.2k ( 작성자는 한국인.. )
-   simple
-   high performance
-   last update : 3 years ago
-   minimum g++ 4.8, c++11(header-only)

3. [uWebSockets](https://github.com/uNetworking/uWebSockets)
-   start 12.2k
-   c++17 header-only
-   based [uSockets](https://github.com/uNetworking/uSockets)
-   clang??  

4. [Mongoose](https://github.com/cesanta/mongoose)
-   6.8k
-   event-driven non-blocking APIs for TCP,UDP,HTTP,WebSocket, MQTT
-   GNU GPL v.2, + 상업용 라이센스 ??
-   임베디드용 http 서버?

5. [restbed](https://github.com/Corvusoft/restbed)
-   stars 1.4k

6. [Pistache](http://pistache.io/)

7. [ngrest](https://github.com/loentar/ngrest.git)

8. [beast](https://github.com/boostorg/beast)

9. [libmicrohttpd](https://www.gnu.org/software/libmicrohttpd/)

10. [libHTTP](https://github.com/lammertb/libhttp)

11. [civetweb](https://github.com/civetweb/civetweb)

부록. [asio](https://www.boost.org/doc/libs/1_75_0/doc/html/boost_asio.html)  

부록. [websocketpp](https://github.com/zaphoyd/websocketpp)

부록. [json11](https://github.com/dropbox/json11)

부록. [uSockets](https://www.boost.org/doc/libs/1_75_0/doc/html/boost_asio.html)
-   c++17
-   cross platform async networking
-   clang??


## http 2

1. [nghttp2](https://nghttp2.org/documentation/index.html)
-   start 3.6k
-   license : MIT Lisence
c 언어로 만들어진 http2 라이브러리.
c++ boost asio 와 래핑하여 사용 가능, libev, libevent 사용 


nghttp, nghttpd, nghttpxx 및 h2load 를 빌드, 실행하려면
OpenSSL
libev
zlib
libc-ares
libxml2
libsystemd-dev
jansson
libevent-openssl
jemalloc
libboost-dev
libboost-thread-dev



추가 ( c++ 도 사용할 경우)

