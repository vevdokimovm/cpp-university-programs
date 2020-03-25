#include <iostream>
#include <typeinfo>

int main(){
    int* p = new int();
    int const * p1 = new const int();
    p = (int*)p1;
}
