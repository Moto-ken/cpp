
#include "Dog.hpp"

Dog::Dog() : Animal("dog") {
    brain = new Brain();
    std::cout << "Dog is created" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    brain = new Brain(*other.brain);
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    std::cout << "Dog assignment operator called" << std::endl;
    return (*this);
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog is destroyed" << std::endl;
}

void Dog::makeSound() const { std::cout << "wan" << std::endl; }
