#include <vector>
#include "inc.hpp"

template <typename ... T>
struct S
{
    int a;
    // template <typename U>
    // using push = S<U, T...>;
    // template <typename U>
    // using push_back = S<T..., U>;
    // template <template<typename ... Args> class U>
    // using rebind = U<T...>;
};

int main(int argc, char*argv[]) {

    S<int, std::string, int> s;
    s.a = 100;
    
    return 0;
}

