
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << "WrongCat is created" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other) WrongAnimal::operator=(other);
    std::cout << "Cat assignment operator called" << std::endl;
    return (*this);
}

WrongCat::~WrongCat() { std::cout << "WrongCat is destroyed" << std::endl; }

void WrongCat::makeSound() const { std::cout << "にゃー" << std::endl; }
