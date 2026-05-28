
#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal is created" << std::endl;
}

Animal::Animal(const Animal& other) {
    *this = other;
    std::cout << "Animal class copy constructor called" << std::endl;
}

Animal::Animal(const std::string& name) : type(name) {
    std::cout << "Animal is created" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) type = other.type;
    std::cout << "Animal class assignment operator called" << std::endl;
    return (*this);
}

Animal::~Animal() { std::cout << "Animal is destroyed" << std::endl; }

void Animal::makeSound() const {
    std::cout << "Default animal sound" << std::endl;
}

std::string Animal::getType() const { return (type); }