#include <iostream>
#include <cstddef> //size_t

template<class TypeTo,
         class TypeFrom>
void copy_n_(TypeTo * p, TypeFrom * q, size_t num){
    for (size_t i = 0; i < num; ++i){
        p[i] = TypeTo(q[i]);
    }
}

int main(){
    int ints[] = {1, 2, 3, 4};
    double doubles[4] = {};
    copy_n_(doubles, ints, 4);
    for (size_t i = 0; i < 4; ++i){
        std::cout << doubles[i] << ' ';
    }
    //int a = 5;
    //double b = 5.6;
    //std::cout << (double)a / 2;
}
