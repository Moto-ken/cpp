
#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource() {
    // std::cout << "IMateriaSource created" << std::endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource& other) {
    (void)other;
    // std::cout << "IMateriaSource copied" << std::endl;
}

IMateriaSource& IMateriaSource::operator=(const IMateriaSource& other) {
    (void)other;
    // std::cout << "IMateriaSource assigned" << std::endl;
    return (*this);
}

IMateriaSource::~IMateriaSource() {
    // std::cout << "IMateriaSource destroyed" << std::endl;
}
