#include <iostream>
#include <typeinfo>

using namespace std;

void print_values(std::ostream&) {}

template<typename T, typename... Args>
void print_values(std::ostream& os, T const& value, Args const&... args){
    os << typeid(value).name() << ": " << value << std::endl;
    print_values(os, args...);
}

int main()
{
    print_values(std::cout, 0, 3.5, "Hello");
}
