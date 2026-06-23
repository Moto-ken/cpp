
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cctype>
#include <cerrno>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

enum Type { CHAR, INT, FLOAT, DOUBLE, FLOAT_PSEUDO, DOUBLE_PSEUDO, INVALID };

class ScalarConverter {
   private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter&);
    ~ScalarConverter();

    static Type detectType(const std::string& literal);
    static double parse(const std::string& literal, Type type);

    static void printChar(double value);
    static void printInt(double value);
    static void printFloat(double value);
    static void printDouble(double value);
    static void printFloatPseudo(const std::string& literal);
    static void printDoublePseudo(const std::string& literal);
    static void printImpossible();

   public:
    static void convert(const std::string& literal);
};

#endif
