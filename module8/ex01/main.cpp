
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Span.hpp"

int main(void) {
    Span sp = Span(10000);

    std::srand(std::time(0));
    for (int i = 0; i < 10000; ++i) {
        // rand() returns a value between 0 and RAND_MAX on my system.
        // RAND_MAX = 2147483647
        sp.addNumber(std::rand());
    }

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    return 0;
}
