
#include "Animal.hpp"

Animal::Animal() {}

Animal::Animal(const Animal& other) { *this = other; }

Animal::Animal(const std::string& name) : type(name) {}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) type = other.type;
    return (*this);
}

Animal::~Animal() { std::cout << "Animal is destroyed" << std::endl; }

void Animal::makeSound() const {
    std::cout << "Default animal sound" << std::endl;
}

std::string Animal::getType() const { return (type); }