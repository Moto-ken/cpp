
#include <iterator>

#include "Span.hpp"

template <typename Iterator>
void Span::addNumber(Iterator begin, Iterator end) {
    if (std::distance(begin, end) + _numbers.size() > _N)
        throw std::runtime_error("Cannot add more numbers, capacity reached.");
    _numbers.insert(_numbers.end(), begin, end);
}
