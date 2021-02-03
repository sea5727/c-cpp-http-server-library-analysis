#include "inc.hpp"

void
function(const char arr[10]){

}
struct OutOfRange
{
    OutOfRange(unsigned /*pos*/, unsigned /*length*/) {}
};
constexpr unsigned requires_in_range( unsigned i, unsigned len )
{
    return i >= len ? throw OutOfRange(i, len) : i;
}
class const_str
{
    const char * const begin_;
    unsigned size_;
    public:
    template< unsigned N >
        constexpr const_str( const char(&arr)[N] ) : begin_(arr), size_(N - 1) {
            static_assert( N >= 1, "not a string literal");
        }
    constexpr char operator[]( unsigned i ) const { 
        
        return requires_in_range(i, size_), begin_[i]; 
    }
    constexpr operator const char *() const { 
        return begin_; 
    }
    constexpr const char* begin() const { return begin_; }
    constexpr const char* end() const { return begin_ + size_; }
    constexpr unsigned size() const { 
        return size_; 
    }
};

const char * const testf = "test";
constexpr char mytestf( unsigned i ) { 
        
    return requires_in_range(0, 10), testf[0]; 
}
char mytestf2(unsigned i) {
    return 0, testf[0]; 
}
int mytestf3(unsigned i){
    return 0, 1;
}
int main(int argc, char*argv[]) {

    std::cout << "crow-tutorial" << std::endl;
    
    black_magic::OutOfRange s(0, 0);
    int j = 50;
    
    for(int i = 0 ; i < 50 ; i++){
        auto t = black_magic::requires_in_range(i, j);
        char buffer[i];
        std::cout << "buffer size : " << sizeof(buffer) << std::endl;
        // std::cout << "t:" << t << std::endl;
    }

    const_str str2("myteststring2");
    printf("%c\n", str2[0]);
    
    
    // black_magic::const_str str("myteststring");
    // str[0];
    
    return 0;
}