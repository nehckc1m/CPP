#pragma once

static const char* SPECIALCASE[]  = {"+inf", "-inf", "nan"};
static const char* SPECIALCASEF[]  = {"+inff", "-inff", "nanf"};

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <cctype>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
    public:
        ~ScalarConverter();
        static void isSpecialCase(const std::string &literal, bool isFloat);
        static void convert(const std::string &literal);
        static bool checkArg(const std::string &literal);
};