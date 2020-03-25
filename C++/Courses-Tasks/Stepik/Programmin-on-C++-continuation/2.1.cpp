#include <iostream>
#include <typeinfo>

void print_values(std::ostream os) { return ; }

template<typename T, typename... Args>
void print_values(std::ostream& os, T value, Args... args){
    os << typeid(value).name() << " : " << value;
    print_values(os, args...);
    return;
}

int main()
{
    print_values(std::cout, 0, 3.5, "Hello");
}
