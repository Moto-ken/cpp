
#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource() {
    for (size_t i = 0; i < 4; i++) {
        _memory[i] = NULL;
    }
    std::cout << "MateriaSource created" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) : IMateriaSource() {
    for (size_t i = 0; i < 4; i++) {
        _memory[i] = NULL;
    }
    *this = other;
    std::cout << "MateriaSource copied" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        for (size_t i = 0; i < 4; i++) {
            delete _memory[i];
            if (other._memory[i])
                _memory[i] = other._memory[i]->clone();
            else
                _memory[i] = NULL;
        }
    }
    std::cout << "MateriaSource assigned" << std::endl;
    return (*this);
}

MateriaSource::~MateriaSource() {
    for (size_t i = 0; i < 4; i++) {
        delete _memory[i];
    }
    std::cout << "MateriaSource destroyed" << std::endl;
}

void MateriaSource::learnMateria(AMateria* materia) {
    for (size_t i = 0; i < 4; i++) {
        if (_memory[i] == NULL) {
            _memory[i] = materia->clone();
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const& type) {
    for (size_t i = 0; i < 4; i++) {
        if (_memory[i] && _memory[i]->getType() == type)
            return (_memory[i]->clone());
    }
    return (NULL);
}
