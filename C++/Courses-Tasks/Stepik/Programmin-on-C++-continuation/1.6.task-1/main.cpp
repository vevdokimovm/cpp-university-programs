#include <iostream>

template<typename T,
         typename V>
bool compare(const T& a, const T& b, V (T::*ptrmethod)() const){
    if (((a.*ptrmethod)()) < ((b.*ptrmethod)()))
        return true;
    return false;
}

int main()
{
    std::string s1("elf");
    std::string s2("archer");
    std::cout << (compare(s1, s2, &std::string::size));
    return 0;
}
