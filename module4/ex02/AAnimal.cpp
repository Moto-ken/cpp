
#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal") {
    std::cout << "AAnimal is created" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) {
    *this = other;
    std::cout << "AAnimal class copy constructor called" << std::endl;
}

AAnimal::AAnimal(const std::string& name) : type(name) {
    std::cout << "AAnimal is created" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    if (this != &other) type = other.type;
    std::cout << "AAnimal class assignment operator called" << std::endl;
    return (*this);
}

AAnimal::~AAnimal() { std::cout << "AAnimal is destroyed" << std::endl; }

std::string AAnimal::getType() const { return (type); }