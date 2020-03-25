#include <iostream>
#include <cstring>
#include <cstdlib>
#include <typeinfo>
#include <type_traits>
#include <cstdlib>

using std::cout;
using std::endl;

void printf(char const * s){
    while(*s){
        if (*s == '%' && *(++s) != '%')
            std::cout << *s++;
    }
}

template<class T, class... Args>
void printf(char const* s, T value, Args... args){
    while(*s){
        if (*s == '%' && *(++s) != '%'){
            cout << value;
            printf(++s, args...);
            return;
        }
        std::cout << *s++;
    }
}

int main(){
    printf("Hello %d Vasya", 5.5);
}
