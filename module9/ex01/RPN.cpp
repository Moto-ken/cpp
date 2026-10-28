
#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) _stack = other._stack;
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string& token) {
    return token.size() == 1 && (token[0] == '+' || token[0] == '-' ||
                                 token[0] == '*' || token[0] == '/');
}

void RPN::applyOperator(char op) {
    if (_stack.size() < 2) throw std::runtime_error("Error");
    double b = _stack.top();
    _stack.pop();
    double a = _stack.top();
    _stack.pop();

    double result;
    if (op == '+')
        result = a + b;
    else if (op == '-')
        result = a - b;
    else if (op == '*')
        result = a * b;
    else {
        if (b == 0) throw std::runtime_error("Error");
        result = a / b;
    }

    if (result > INT_MAX || result < INT_MIN) throw std::runtime_error("Error");
    _stack.push(result);
}

double RPN::evaluate(const std::string& expr) {
    while (!_stack.empty()) _stack.pop();

    std::stringstream ss(expr);
    std::string token;
    while (ss >> token) {
        if (token.size() == 1 &&
            std::isdigit(static_cast<unsigned char>(token[0])))
            _stack.push(token[0] - '0');
        else if (isOperator(token))
            applyOperator(token[0]);
        else
            throw std::runtime_error("Error");
    }

    if (_stack.size() != 1) throw std::runtime_error("Error");
    return _stack.top();
}
