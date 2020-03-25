#include <iostream>
#include <typeinfo>

using namespace std;

class Array {
public:
    int operator[](int)  { return data; }
    int data = 5;
};


struct Unit {
    // наличие виртуальных методов необходимо
    virtual ~Unit() { }
};

struct Elf : Unit { };

int main() {
    Elf e;
    Unit & ur = e;
    Unit * up = &e;
    cout << typeid(ur).name() << endl;   // Elf
    cout << typeid(*up).name() << endl;  // Elf
    cout << typeid(up) .name() << endl;  // Unit *
    cout << typeid(Elf).name() << endl;  // Elf
    cout << (typeid(ur) == typeid(Elf)); // 1
    cout << typeid(Array).name() << endl;
}
