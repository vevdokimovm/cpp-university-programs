#include <iostream>
#include <typeinfo>
#include <conio.h>

using namespace std;

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
    _getch();
    return 0;
}
