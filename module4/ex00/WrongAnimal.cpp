
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {}

WrongAnimal::WrongAnimal(const WrongAnimal& other) { *this = other; }

WrongAnimal::WrongAnimal(const std::string& name) : type(name) {}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other) type = other.type;
    return (*this);
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal is destroyed" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "Default animal sound" << std::endl;
}

std::string WrongAnimal::getType() const { return (type); }
