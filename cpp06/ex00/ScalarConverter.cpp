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



void ScalarConverter::convert(const std::string &literal) {
 
    // Conversion logic will be implemented here
    char *end;
    double value = std::strtod(literal.c_str(), &end);
    size_t pos;

    std::cout << "ntm:" << value << std::endl;
    if (literal.length() == 3 && isprint(static_cast<char>(literal[1])))
    {
        std::cout <<"in da condition" << std::endl;
        std::cout << "char: " << literal << std::endl;
        std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
        std::cout << "float: " << static_cast<float>(literal[0]) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(literal[0]) << ".0"<< std::endl;
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
    if (value < std::numeric_limits<float>::min() || value > std::numeric_limits<float>::max()) {
        std::cout << "float: impossible" << std::endl;
    } else if (pos != std::string::npos) {
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    }
    else {
        std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
    }
    if (value < std::numeric_limits<double>::min() || value > std::numeric_limits<double>::max()) {
        std::cout << "double: impossible" << std::endl;
    } else if (pos != std::string::npos) {
        std::cout << "double: " << value << std::endl;
    }
    else {
        std::cout << "double: " << value << ".0" << std::endl;
    }
}