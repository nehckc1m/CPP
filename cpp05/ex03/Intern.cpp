#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &other) {
    (void)other;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other) {
    if (this != &other) {
        return *this;
    }
    return *this;
};

Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

static AForm *createShrubberyCreationForm(std::string target) {
    return new ShrubberyCreationForm(target);
}

static AForm *createRobotomyRequestForm(std::string target) {
    return new RobotomyRequestForm(target);
}

static AForm *createPresidentialPardonForm(std::string target) {
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
    std::string forms[] = {"PresidentialPardon", "RobotomyRequest", "ShrubberyCreation"};
    AForm *(*formCreator[])(std::string target) = {&createPresidentialPardonForm,
                                                   &createRobotomyRequestForm,
                                                   &createShrubberyCreationForm};
    for (int i = 0; i < 3; ++i) {
        if (forms[i] == formName) {
            std::cout << "Intern creates " << forms[i] << std::endl;
            return formCreator[i](target);
        }
    }
    std::cout << "Intern cannot create form " << formName << std::endl;
    return NULL; 
}
