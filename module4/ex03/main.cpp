
#include "character/Character.hpp"
#include "materia/AMateria.hpp"
#include "materia/Cure.hpp"
#include "materia/Ice.hpp"

int main() {
    Character a("Alice");
    Character b("Bob");

    std::cout << "---------------------------" << std::endl;
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();
    a.equip(ice);
    a.equip(cure);
    std::cout << "---------------------------" << std::endl;
    a.use(0, b);  // Ice
    a.use(1, b);  // Cure
    std::cout << "---------------------------" << std::endl;
    a.unequip(0);
    a.use(0, b);  // 何も出ないはず
    std::cout << "---------------------------" << std::endl;
    Character c = a;
    c.use(1, b);  // Cureは残っているはず
    std::cout << "---------------------------" << std::endl;

    return 0;
}
