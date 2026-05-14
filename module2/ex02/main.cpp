
#include <iostream>

#include "Fixed.hpp"

int main() {
    std::cout << "===== constructors =====" << std::endl;
    Fixed a;
    Fixed b(10);
    Fixed c(42.42f);
    Fixed d(b);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;

    std::cout << "\n===== comparison =====" << std::endl;

    Fixed x(5.5f);
    Fixed y(2.25f);

    std::cout << (x > y) << std::endl;
    std::cout << (x < y) << std::endl;
    std::cout << (x >= y) << std::endl;
    std::cout << (x <= y) << std::endl;
    std::cout << (x == y) << std::endl;
    std::cout << (x != y) << std::endl;

    std::cout << "\n===== arithmetic =====" << std::endl;

    std::cout << "x + y = " << x + y << std::endl;
    std::cout << "x - y = " << x - y << std::endl;
    std::cout << "x * y = " << x * y << std::endl;
    std::cout << "x / y = " << x / y << std::endl;

    std::cout << "\n===== increment =====" << std::endl;

    Fixed i;

    std::cout << i << std::endl;
    std::cout << ++i << std::endl;
    std::cout << i << std::endl;
    std::cout << i++ << std::endl;
    std::cout << i << std::endl;

    std::cout << "\n===== decrement =====" << std::endl;

    std::cout << --i << std::endl;
    std::cout << i-- << std::endl;
    std::cout << i << std::endl;

    std::cout << "\n===== min/max =====" << std::endl;

    Fixed m1(100.1f);
    Fixed m2(99.9f);

    std::cout << "min = " << Fixed::min(m1, m2) << std::endl;
    std::cout << "max = " << Fixed::max(m1, m2) << std::endl;

    std::cout << "\n===== subject test =====" << std::endl;

    Fixed aa;
    Fixed const bb(Fixed(5.05f) * Fixed(2));

    std::cout << aa << std::endl;
    std::cout << ++aa << std::endl;
    std::cout << aa << std::endl;
    std::cout << aa++ << std::endl;
    std::cout << aa << std::endl;

    std::cout << bb << std::endl;

    std::cout << Fixed::max(aa, bb) << std::endl;

    return 0;
}
