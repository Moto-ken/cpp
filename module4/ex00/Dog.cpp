
#include "dog.hpp"

Dog::Dog() : Animal("dog") { std::cout << "Dog is created" << std::endl; }

Dog::Dog(const Dog& other) : Animal(other) {}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) Animal::operator=(other);
    return (*this);
}

Dog::~Dog() { std::cout << "Dog is destroyed" << std::endl; }

void Dog::makeSound() const { std::cout << "wan" << std::endl; }
