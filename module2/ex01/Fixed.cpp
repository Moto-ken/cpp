
#include "Fixed.hpp"

// default constructor
Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// constructor
Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    value = n << fractionalBits;
}

Fixed::Fixed(const float n) {
    std::cout << "Float constructor called" << std::endl;
    if (n >= 0)
        this->value = (int)(n * (1 << fractionalBits) + 0.5f);
    else
        this->value = (int)(n * (1 << fractionalBits) - 0.5f);
}

// copy constructor
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    // this->value = other.value;
    *this = other;
    // this->value = other.getRawBits();
}

// copy assignment operator
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->value = other.value;
        // this->value = other.getRawBits();
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

float Fixed::toFloat(void) const {
    return ((float)value / (1 << fractionalBits));
}

int Fixed::toInt(void) const { return (value >> fractionalBits); }

// stream insertion operator overload
std::ostream& operator<<(std::ostream& out, const Fixed& value) {
    out << value.toFloat();
    return (out);
}
