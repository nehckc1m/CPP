#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    (void)other; // Prevent unused parameter warning
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    if (this != &other) {
        // Copy assignment logic if needed
    }
    return *this;
}

void ScalarConverter::isSpecialCase(const std::string &literal, bool isFloat)
{
    std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: Non displayable" << std::endl;
    
    if (isFloat)
    {
        std::cout << "float: " << literal << std::endl;
        std::string withoutF = literal.substr(0, literal.length() -1);
        std::cout << "double: " << withoutF << std::endl;
    }
    else{
        std::cout << "float: " << literal << "f" << std::endl;
        std::cout << "double: " << literal << std::endl;
    }
}

bool ScalarConverter::checkArg(const std::string &literal)
{
    int i = -1;

    while (literal[++i])
    {
        std::cout << literal[i] << std::endl;
        if (i == 0 && (literal[i] == '+' || literal[i] == '-'))
            i++;
        if (!(literal[i] >= '0' && literal[i] <= '9') && literal[i] != '.' && literal[i] != 'f')
            return (0);
        if (literal[i] == 'f' && literal[i + 1])
            return (0);
    }
    return (1);
}

void ScalarConverter::convert(const std::string &literal) {
    char *end;
    double value = std::strtod(literal.c_str(), &end);
    size_t pos;

    for (int i = 0; i < 3; i++) {
        if (literal == SPECIALCASE[i]){
            isSpecialCase(literal, false);
            return;
        }
        if (literal == SPECIALCASEF[i]){
            isSpecialCase(literal, true);
            return;
        }
    }

    if ((literal.length() == 1 && isprint(static_cast<char>(literal[0])) && !isdigit(literal[0])))
    {
        std::cout << "char: " << literal << std::endl;
        std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
        std::cout << "float: " << static_cast<float>(literal[0]) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(literal[0]) << ".0"<< std::endl;
        return;

    }
    if (checkArg(literal) == 0)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" <<  std::endl;
        std::cout << "double: impossible" <<  std::endl;
        return;
    }

    if (isprint(static_cast<char>(value)))
        std::cout << "char: " << static_cast<char>(value) << std::endl;
    else {
        std::cout << "char: impossible" << std::endl;
    } 
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }
    pos = literal.find('.');

    if (value < -3.40282e+38  || static_cast<float>(value) > std::numeric_limits<float>::max()) {
        std::cout << "float: impossible" << std::endl;
    } else if (pos != std::string::npos && (value != std::floor(value))) {
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    }
    else {
        std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
    }


    if (value < -1.79769e+308 || value > std::numeric_limits<double>::max()) {
        std::cout << "double: impossible" << std::endl;
    } else if (pos != std::string::npos && (value != std::floor(value))) {
        std::cout << "double: " << static_cast<double>(value) << std::endl;
    }
    else {
        std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
    }
}