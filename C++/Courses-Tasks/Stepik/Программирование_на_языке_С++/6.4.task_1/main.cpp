#include <iostream>
#include <cstddef>

template<class T, size_t S>
size_t array_size(T (&a)[S]){
    return S;
}

int main()
{
    int ints[] = {1, 2, 3, 4};
    int *iptr = ints;
    double doubles[] = {3.14};
    std::cout <<array_size(ints); // вернет 4
    std::cout<<array_size(doubles); // вернет 1
    //array_size(iptr); // тут должна произойти ошибка компиляции
}

