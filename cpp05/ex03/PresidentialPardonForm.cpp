#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {
    std::cout << "Parameterized constructor called for PresidentialPardonForm: " << _target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
    : AForm(copy), _target(copy._target) {
    std::cout << "Copy constructor called for PresidentialPardonForm: " << _target << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "Destructor called for PresidentialPardonForm: " << _target << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
    if (this != &copy) {
        AForm::operator=(copy);
        _target = copy._target;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (!getSign()) {
        throw AForm::FormNotSigned();
    }
    if (executor.getGrade() > getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }
    std::cout << executor.getName() << " executed" << getName() << std::endl;
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

const std::string &PresidentialPardonForm::getTarget() const {
    return _target;
}