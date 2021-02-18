#include <iostream>


template <int N>
struct single_tag_to_type
{ };

template <>
struct single_tag_to_type<1>
{
    using type = int64_t;
};

template <>
struct single_tag_to_type<2>
{
    using type = uint64_t;
};

using myint = single_tag_to_type<1>;


int main(int argc, char *argv[]){
    single_tag_to_type<1>::type a = 123;
    printf("a : %d\n", a);
}