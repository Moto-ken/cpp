
#include "ICharacter.hpp"

ICharacter::ICharacter() {
    // std::cout << "ICharacter created" << std::endl;
}

ICharacter::ICharacter(const ICharacter& other) {
    (void)other;
    // std::cout << "ICharacter copied" << std::endl;
}

ICharacter& ICharacter::operator=(const ICharacter& other) {
    (void)other;
    // std::cout << "ICharacter assigned" << std::endl;
    return (*this);
}

ICharacter::~ICharacter() {
    // std::cout << "ICharacter destroyed" << std::endl;
}
