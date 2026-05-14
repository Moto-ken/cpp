
#include "Fixed.hpp"

#include <iostream>

// default constructor
Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// constructor
Fixed::Fixed(const int value) {
    // int -> kotei
}

Fixed::Fixed(const float value) {
    // float -> koteisyouusuutenn
}

// copy constructor
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    // this->value = other.value;
    this->value = other.getRawBits();
}

// hikau dainyuu
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        // this->value = other.value;
        this->value = other.getRawBits();
    }
    return (*this);
}

// destrunctor
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (value);
}

void Fixed::setRawBits(int const raw) { value = raw; }

float Fixed::toFloat(void) const {}

int Fixed::toInt(void) const {}

//
std::ostream& operator<<(std::ostream& out, const Fixed& value) {
    out << value.toFloat();
    return out;
}
