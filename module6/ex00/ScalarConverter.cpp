
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) {
    return *this;
}

Type ScalarConverter::detectType(const std::string& s) {
    if (s.empty()) return INVALID;
    if (s == "nanf" || s == "+inff" || s == "-inff") return FLOAT_PSEUDO;
    if (s == "nan" || s == "+inf" || s == "-inf") return DOUBLE_PSEUDO;
    if (s.length() == 1 && !isdigit(static_cast<unsigned char>(s[0])))
        return CHAR;

    bool dot = false;
    bool f = false;
    size_t i = 0;
    if (s[0] == '+' || s[0] == '-') i++;
    while (i < s.size()) {
        if (s[i] == '.') {
            if (dot) return INVALID;
            dot = true;
        } else if (s[i] == 'f' && i == s.size() - 1) {
            f = true;
        } else if (!isdigit(static_cast<unsigned char>(s[i]))) {
            return INVALID;
        }
        i++;
    }
    if (f) return FLOAT;
    if (dot) return DOUBLE;
    return INT;
}

double ScalarConverter::parse(const std::string& s, Type type) {
    if (type == CHAR) return static_cast<double>(s[0]);
    char* end;
    errno = 0;
    if (type == INT) {
        long value = std::strtol(s.c_str(), &end, 10);
        if (*end != '\0') throw std::invalid_argument("invalid int");
        if (errno == ERANGE) throw std::out_of_range("number too large");
        return static_cast<double>(value);
    }
    double value = std::strtod(s.c_str(), &end);
    if (*end != '\0') throw std::invalid_argument("invalid double");
    if (errno == ERANGE) throw std::out_of_range("double overflow");
    return value;
}

void ScalarConverter::convert(const std::string& literal) {
    Type type = detectType(literal);
    if (type == INVALID) {
        printImpossible();
        return;
    }
    if (type == FLOAT_PSEUDO) {
        printFloatPseudo(literal);
        return;
    }
    if (type == DOUBLE_PSEUDO) {
        printDoublePseudo(literal);
        return;
    }
    try {
        double value = parse(literal, type);
        printChar(value);
        printInt(value);
        printFloat(value);
        printDouble(value);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void ScalarConverter::printChar(double value) {
    if (std::isnan(value) || value < 0 || value > 127) {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    char c = static_cast<char>(value);
    if (!std::isprint(c)) {
        std::cout << "char: Non displayable" << std::endl;
        return;
    }
    std::cout << "char: '" << c << "'" << std::endl;
}

void ScalarConverter::printInt(double value) {
    if (std::isnan(value) || value > INT_MAX || value < INT_MIN) {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value) {
    std::cout << "float: ";
    if (std::isnan(value)) {
        std::cout << "nanf" << std::endl;
        return;
    }
    if (std::isinf(value)) {
        if (value < 0) {
            std::cout << "-inff" << std::endl;
        } else {
            std::cout << "+inff" << std::endl;
        }
        return;
    }
    if (value > static_cast<double>(FLT_MAX) ||
        value < -static_cast<double>(FLT_MAX)) {
        std::cout << "impossible" << std::endl;
        return;
    }
    std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value)
              << "f" << std::endl;
}

void ScalarConverter::printDouble(double value) {
    std::cout << "double: ";
    if (std::isnan(value)) {
        std::cout << "nan" << std::endl;
        return;
    }
    if (std::isinf(value)) {
        std::cout << (value < 0 ? "-inf" : "+inf") << std::endl;
        return;
    }
    std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}

void ScalarConverter::printFloatPseudo(const std::string& s) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << s << std::endl;
    std::string d = s.substr(0, s.size() - 1);
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::printDoublePseudo(const std::string& s) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << s << "f" << std::endl;
    std::cout << "double: " << s << std::endl;
}

void ScalarConverter::printImpossible() {
    std::cout << "printImpossible" << std::endl;
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}
