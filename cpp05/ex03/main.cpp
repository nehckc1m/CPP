#include "Bureaucrat.hpp"
#include <stdexcept>
#include <iostream>
#include <string>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main() {
    srand(time(NULL));
    Bureaucrat b1("Alice", 1);
    ShrubberyCreationForm shrubberyForm("Garden");
    std::cout << shrubberyForm << std::endl;
    b1.executeForm(shrubberyForm); // This should throw an exception since the form is not signed
    b1.signForm(shrubberyForm);
    std::cout << "After signing: " << shrubberyForm << std::endl;
    std::cout << b1 << std::endl;
    b1.executeForm(shrubberyForm);

    RobotomyRequestForm robotomyForm("toto");
    b1.signForm(robotomyForm);
    b1.executeForm(robotomyForm); // This should execute the robotomy request
    PresidentialPardonForm presidentialForm("President");
    b1.signForm(presidentialForm);
    b1.executeForm(presidentialForm); // This should execute the presidential pardon
    Intern intern;
    AForm *form1 = intern.makeForm("ShrubberyCreation", "Home");
    b1.signForm(*form1);
    b1.executeForm(*form1); // This should execute the shrubbery creation form
    delete form1;
    return 0;
}