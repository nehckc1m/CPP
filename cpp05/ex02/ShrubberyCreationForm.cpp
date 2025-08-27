#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    std::cout << "Parameterized constructor called for ShrubberyCreationForm: " << _target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
    : AForm(copy), _target(copy._target) {
    std::cout << "Copy constructor called for ShrubberyCreationForm: " << _target << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "Destructor called for ShrubberyCreationForm: " << _target << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
    if (this != &copy) {
        AForm::operator=(copy);
        _target = copy._target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    std::string fileName = _target + "_shrubbery";
    if (!getSign()) {
        throw AForm::FormNotSigned();
    }
    if (executor.getGrade() > getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }
    std::ofstream outFile(fileName.c_str());
    if (!outFile) {
        throw std::runtime_error("Failed to open file for writing.");
    }
    outFile << ASCII_TREE;
    outFile.close();
    std::cout << "Shrubbery created in file: " << fileName << std::endl;
}