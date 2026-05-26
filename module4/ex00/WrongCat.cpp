
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << "WrongCat is created" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other) WrongAnimal::operator=(other);
    return (*this);
}

WrongCat::~WrongCat() { std::cout << "WrongCat is destroyed" << std::endl; }

void WrongCat::makeSound() const { std::cout << "にゃー" << std::endl; }
