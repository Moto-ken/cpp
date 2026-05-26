
#include "Fixed.hpp"

// default constructor
Fixed::Fixed() : value(0) {}

// constructor overload
Fixed::Fixed(const int n) { value = n << fractionalBits; }

Fixed::Fixed(const float n) {
    if (n >= 0)
        this->value = (int)(n * (1 << fractionalBits) + 0.5f);
    else
        this->value = (int)(n * (1 << fractionalBits) - 0.5f);
}

// copy constructor
Fixed::Fixed(const Fixed& other) : value(other.value) {}

// copy assignment operator
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        this->value = other.value;
    }
    return (*this);
}

// destrunctor
Fixed::~Fixed() {}

int Fixed::getRawBits(void) const { return (value); }

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

// comparison
bool Fixed::operator>(const Fixed& other) const {
    return (this->value > other.value);
}

bool Fixed::operator<(const Fixed& other) const {
    return (this->value < other.value);
}

bool Fixed::operator>=(const Fixed& other) const {
    return (this->value >= other.value);
}

bool Fixed::operator<=(const Fixed& other) const {
    return (this->value <= other.value);
}

bool Fixed::operator==(const Fixed& other) const {
    return (this->value == other.value);
}

bool Fixed::operator!=(const Fixed& other) const {
    return (this->value != other.value);
}

// arthmetic
Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->value + other.value);
    return (result);
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->value - other.value);
    return (result);
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;

    long long mul = static_cast<long long>(this->value) *
                    static_cast<long long>(other.value);
    if (mul >= 0)
        mul += (1LL << (fractionalBits - 1));
    else
        mul -= (1LL << (fractionalBits - 1));
    result.setRawBits(mul >> fractionalBits);
    return (result);
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;

    if (other.value == 0) throw std::runtime_error("division by zero");
    long long div =
        (static_cast<long long>(this->value) << fractionalBits) / other.value;
    result.setRawBits(div);
    return (result);
}

// increments
Fixed& Fixed::operator++() {
    this->value += 1;
    return (*this);
}

Fixed Fixed::operator++(int) {
    Fixed tmp = *this;
    this->value += 1;
    return (tmp);
}

Fixed& Fixed::operator--() {
    this->value -= 1;
    return (*this);
}

Fixed Fixed::operator--(int) {
    Fixed tmp = *this;
    this->value -= 1;
    return (tmp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    if (a < b) return (a);
    return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    if (a > b) return (a);
    return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    if (a < b) return (a);
    return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    if (a > b) return (a);
    return (b);
}
