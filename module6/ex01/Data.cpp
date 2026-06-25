
#include "Data.hpp"

Data::Data() : nb(0) {}

Data::Data(const Data& other) : nb(other.nb) {}

Data::Data(const int nb) : nb(nb) {}

Data& Data::operator=(const Data& other) {
    if (this != &other) {
        this->nb = other.nb;
    }
    return *this;
}

Data::~Data() {}
