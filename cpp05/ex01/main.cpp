#include "Bureaucrat.hpp"
#include <stdexcept>
#include <iostream>
#include <string>

int main() {

    Bureaucrat b1("Alice", 50);
    Form f1("contract", 50, 50);
    std::cout << f1 << std::endl;
    std::cout << b1 << std::endl;
    b1.signForm(f1);
    std::cout << "After signing: " << f1 << std::endl;
    Bureaucrat b2("Bob", 51); // This should throw an exception
    Form f2("agreement", 50, 50);
    b2.signForm(f2); // This should fail to sign the form
    std::cout << f2 << std::endl;
    b2.signForm(f1); // This should not sign the form since it's already signed
    return 0;
}