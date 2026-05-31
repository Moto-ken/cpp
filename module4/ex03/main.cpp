
#include "character/Character.hpp"
#include "materia/AMateria.hpp"
#include "materia/Cure.hpp"
#include "materia/Ice.hpp"
#include "materiaSource/MateriaSource.hpp"

int main() {
    Character alice("Alice");
    Character bob("Bob");
    MateriaSource src;
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();
    // src.learnMateria(new Ice());

    src.learnMateria(ice);
    src.learnMateria(cure);
    delete ice;
    delete cure;
    AMateria* m1 = src.createMateria("ice");
    AMateria* m2 = src.createMateria("cure");
    alice.equip(m1);
    alice.equip(m2);
    alice.use(0, bob);
    alice.use(1, bob);
    AMateria* unknown = src.createMateria("fire");
    if (!unknown) std::cout << "fire not found" << std::endl;

    return 0;
}
