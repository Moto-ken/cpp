
#include <iostream>

#include "../character/ICharacter.hpp"
#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

class DummyCharacter : public ICharacter {
   private:
    std::string _name;

   public:
    DummyCharacter(std::string name) : _name(name) {}
    virtual ~DummyCharacter() {}
    std::string const& getName() const { return _name; }
    void equip(AMateria* m) { (void)m; }
    void unequip(int idx) { (void)idx; }
    void use(int idx, ICharacter& target) {
        (void)idx;
        (void)target;
    }
};

int main(void) {
    AMateria* materia = new Cure();
    DummyCharacter target("bob");

    materia->use(target);
    std::cout << materia->getType() << std::endl;
    delete materia;

    AMateria* ma = new Ice();
    ma->use(target);
    std::cout << ma->getType() << std::endl;
    delete ma;

    return 0;
}
