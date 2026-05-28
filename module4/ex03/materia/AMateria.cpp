
#include "AMateria.hpp"

AMateria::AMateria() : _type("default") {
    std::cout << "AMateria created" << std::endl;
}

AMateria::AMateria(std::string const& type) : _type(type) {
    std::cout << "AMateria created" << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type) {
    std::cout << "AMateria copied" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
    if (this != &other) _type = other._type;
    std::cout << "AMateria assigned" << std::endl;
    return (*this);
}

AMateria::~AMateria() { std::cout << "AMateria destroyed" << std::endl; }

std::string const& AMateria::getType() const { return (_type); }

void AMateria::use(ICharacter& target) {
    std::cout << "Default materia use" << std::endl;
}