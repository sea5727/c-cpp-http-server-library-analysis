#include <iostream>
#include <string.h>

int fact(int n){
    return (n <= 1) 
        ? 1 : fact(n - 1) * n;
}
constexpr int fact2(int n){
    return (n <= 1) ? 1 : fact2(n-1) * n;
}

int myconstchar(const char * arr, int n){
    printf("arr:%s, n:%d\n", arr, n);
    return 0;
}
int main(int argc, char * argv[]){


    return 0;
}