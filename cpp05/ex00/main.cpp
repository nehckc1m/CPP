#include "Bureaucrat.hpp"
#include <stdexcept>
#include <iostream>
#include <string>

int main() {

        Bureaucrat b1("Alice", 50);
        std::cout << b1 << std::endl;

        b1.incrementGrade();
        std::cout << "After increment: " << b1 << std::endl;

        b1.decrementGrade();
        std::cout << "After decrement: " << b1 << std::endl;

        Bureaucrat b2("Bob", 0); // This should throw an exception
        Bureaucrat b3("Charlie", 151); // This should also throw an exception
        Bureaucrat b4 = b1; // Copy constructor
        Bureaucrat b5("Dave", 1);
        b5.incrementGrade(); // This should throw an exception since Dave's grade is already at the highest level
        std::cout << "After copy and increment: " << b4 << std::endl;
    return 0;
}