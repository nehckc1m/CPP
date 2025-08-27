

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::cout << "Parameterized constructor called for RobotomyRequestForm: " << _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
    : AForm(copy), _target(copy._target) {
    std::cout << "Copy constructor called for RobotomyRequestForm: " << _target << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "Destructor called for RobotomyRequestForm: " << _target << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
    if (this != &copy) {
        AForm::operator=(copy);
        _target = copy._target;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (!getSign()) {
        throw AForm::FormNotSigned();
    }
    if (executor.getGrade() > getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }
    std::cout << executor.getName() << " executed " << getName() << std::endl;
    if (rand() % 2 == 1) {
        std::cout << "Robotomy failed for " << _target << "!" << std::endl;
    } else {
        std::cout << _target << " has been robotomized!" << std::endl;
    }
}

const std::string &RobotomyRequestForm::getTarget() const {
    return _target;
}
