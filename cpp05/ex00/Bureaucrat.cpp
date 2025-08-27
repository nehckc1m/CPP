#include "Bureaucrat.hpp"
#include <stdexcept>

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
    std::cout << "Default constructor called for " << _name << std::endl;

}
Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade) {
    std::cout << "Copy constructor called for " << _name << std::endl;
}
Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade) : _name(name) {
    std::cout << "Parameterized constructor called for " << _name << std::endl;
    try{
        setGrade(grade);
    } catch (const std::exception &err) {
        std::cerr << "Error setting grade for " << _name << ": " << err.what() << std::endl;
    }
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor called for " << _name << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
    if (this != &copy) {
        _grade = copy._grade;
    }
    return *this;
}

const std::string &Bureaucrat::getName() const {
    return _name;
}

unsigned int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::setGrade(unsigned int grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
    _grade = grade;
}

void Bureaucrat::incrementGrade() {
    try {
        setGrade(_grade - 1);
    } catch (const GradeTooHighException &err) {
        std::cerr << err.what() << std::endl;
    } 
}
void Bureaucrat::decrementGrade() {
    try {
        setGrade(_grade + 1);
    } catch (const GradeTooLowException &err) {
        std::cerr << err.what() << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}