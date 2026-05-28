
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "Animal is created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    *this = other;
    std::cout << "WrongAnimal class copy constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& name) : type(name) {
    std::cout << "WrongAnimal is created" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other) type = other.type;
    std::cout << "WrongAnimal class assignment operator called" << std::endl;
    return (*this);
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal is destroyed" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "Default animal sound" << std::endl;
}

std::string WrongAnimal::getType() const { return (type); }
