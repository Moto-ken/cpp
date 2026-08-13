
#include "Span.hpp"

#include <algorithm>
#include <limits>
#include <stdexcept>

// Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span& other) : _N(other._N), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _N = other._N;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

long long Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span.");

    std::vector<int> sortedNumbers = _numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    long long minSpan = std::numeric_limits<long long>::max();
    for (size_t i = 1; i < sortedNumbers.size(); ++i) {
        long long span = static_cast<long long>(sortedNumbers[i]) -
                         static_cast<long long>(sortedNumbers[i - 1]);
        if (span < minSpan) minSpan = span;
    }
    return minSpan;
}

long long Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span.");

    long long minNumber = *std::min_element(_numbers.begin(), _numbers.end());
    long long maxNumber = *std::max_element(_numbers.begin(), _numbers.end());

    return maxNumber - minNumber;
}

void Span::addNumber(int number) {
    if (_numbers.size() >= _N)
        throw std::runtime_error("Cannot add more numbers, capacity reached.");
    _numbers.push_back(number);
}
