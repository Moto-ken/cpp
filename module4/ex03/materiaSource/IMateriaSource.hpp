
#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <iostream>

#include "../materia/AMateria.hpp"

class AMateria;

class IMateriaSource {
   public:
    IMateriaSource();
    IMateriaSource(const IMateriaSource& other);
    virtual IMateriaSource& operator=(const IMateriaSource& other);
    virtual ~IMateriaSource();

    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const& type) = 0;
};

#endif
