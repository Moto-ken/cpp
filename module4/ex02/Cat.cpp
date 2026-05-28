
#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat") {
    brain = new Brain();
    std::cout << "Cat is created" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other) {
    brain = new Brain(*other.brain);
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        AAnimal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    std::cout << "Cat assignment operator called" << std::endl;
    return (*this);
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat is destroyed" << std::endl;
}

void Cat::makeSound() const { std::cout << "にゃー" << std::endl; }

Brain* Cat::getBrain() const { return (brain); }
