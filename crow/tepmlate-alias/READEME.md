# Template-alias


### 기본 타입
```cpp
using identifier = type-id;
```
위와 동일
```cpp
typedef typeid identifier
```

### 함수포인터
```cpp
using func = void(*)(int);
...

void actual_function(int arg) { ... }
func fptr = &actual_function;
```
```cpp
typedef void (*func)(int);
```

### 템플릿 alias

기존 방식은 템플릿 alais가 불가능했기때문에, 구조체 안에 별칭을 숨겨야 함.
::type을 매번 쳐줘야하고, 다른 파라미터로 쓰일경우 가독성 또한 떨어진다.
```cpp
template<typename T>
struct xvector {
    typedef vector<T, xallocator<T>> type;
};

xvector<int>::type idList{1,2,3};

```

using 을 사용한 템플릿 alias
```cpp
template<typename T>
using xvector = vector<T, xallocator<T>>;

xvector<int> idList { 1, 2, 3};
```