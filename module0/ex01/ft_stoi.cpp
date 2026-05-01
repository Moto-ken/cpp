
#include "phonebook.hpp"

int ft_isdigit(char c) { return (c >= '0' && c <= '9'); }

int ft_isspace(char c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' ||
            c == '\f');
}

int ft_stoi(const std::string& s) {
    int i = 0;
    int sign = 1;
    long result = 0;

    if (s.empty()) throw std::invalid_argument("empty string");

    while (i < (int)s.size() && ft_isspace(s[i])) i++;

    if (i < (int)s.size() && (s[i] == '-' || s[i] == '+')) {
        if (s[i] == '-') sign = -1;
        i++;
    }

    if (i >= (int)s.size() || !ft_isdigit(s[i]))
        throw std::invalid_argument("no digits");

    while (i < (int)s.size() && ft_isdigit(s[i])) {
        result = result * 10 + (s[i] - '0');

        if (result > 2147483647) throw std::out_of_range("overflow");

        i++;
    }
    return static_cast<int>(result * sign);
}