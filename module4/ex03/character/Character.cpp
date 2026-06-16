
#include "Character.hpp"

Character::Character() : ICharacter() {
    _name = "default";
    for (size_t i = 0; i < 4; i++) {
        _inventory[i] = NULL;
    }
    std::cout << "Character created" << std::endl;
}

Character::Character(std::string const& name) : ICharacter() {
    _name = name;
    for (size_t i = 0; i < 4; i++) {
        _inventory[i] = NULL;
    }
    std::cout << "Character created" << std::endl;
}

Character::Character(const Character& other) : ICharacter() {
    _name = other._name;
    for (int i = 0; i < 4; i++) {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
    std::cout << "Character copied" << std::endl;
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        _name = other._name;
        for (int i = 0; i < 4; i++) {
            delete _inventory[i];
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
            else
                _inventory[i] = NULL;
        }
    }
    std::cout << "Character copied" << std::endl;
    return (*this);
}

Character::~Character() {
    for (size_t i = 0; i < 4; i++) {
        delete _inventory[i];
    }
    std::cout << "Character deleted" << std::endl;
}

std::string const& Character::getName() const { return (_name); }

void Character::equip(AMateria* m) {
    if (!m) return;
    for (size_t i = 0; i < 4; i++) {
        if (_inventory[i] == NULL) {
            _inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4) return;
    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4) return;
    if (_inventory[idx]) _inventory[idx]->use(target);
}
