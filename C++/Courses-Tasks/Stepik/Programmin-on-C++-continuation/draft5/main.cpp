#include <iostream>

typedef unsigned int unitid;

struct Unit {
    unitid id_;
    int hp_;

    Unit(unitid id, int health_points)
        : id_(id), hp_(health_points)
    {
        std::cout << "Unit constructor" << std::endl;
    }

    void unitInfo() const {
        std::cout << "ID: " << id_ << std::endl;
        std::cout << "HP: " << hp_ << std::endl;
    }
};

struct Elf : Unit {
    explicit Elf(unitid id)
        : Unit(id, 100)
    {
        std::cout << "Elf constructor" << std::endl;
    }
};

struct Archer : Unit {
    explicit Archer(unitid id)
        : Unit(id, 120)
    {
        std::cout << "Archer constructor" << std::endl;
    }
};

struct ElfArcher : Elf, Archer {
    explicit ElfArcher(unitid id)
        :
          Elf(id)
        , Archer(id)
    {
        std::cout << "ElfArcher constructor" << std::endl;
    }
};

int main() {
    ElfArcher elfArcher(728);
    elfArcher.Elf::unitInfo();
}
