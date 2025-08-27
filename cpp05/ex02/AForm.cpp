#include "AForm.hpp"
#include <stdexcept>


AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
    std::cout << "Default constructor called for AForm: " << _name << std::endl;
}
AForm::AForm(const AForm &copy) : _name(copy._name), _isSigned(copy._isSigned), 
                               _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {
    std::cout << "Copy constructor called for AForm: " << _name << std::endl;
}

AForm::AForm(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute) : _name(name), _isSigned(false), 
    _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    std::cout << "Parameterized constructor called for AForm: " << _name << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    } else if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

AForm::~AForm() {
    std::cout << "Destructor called for AForm: " << _name << std::endl;
}

AForm &AForm::operator=(const AForm &copy) {
    if (this != &copy) {
        setSign(copy._isSigned);
        setGradeToSign(copy._gradeToSign);
        setGradeToExecute(copy._gradeToExecute);
    }
    return *this;
}

const std::string &AForm::getName() const {
    return _name;
}

bool AForm::beSigned(const Bureaucrat &bureaucrat){
        
    if (_isSigned) {
        std::cerr << "AForm " << _name << " is already signed." << std::endl;
        return false;
    }
    if (bureaucrat.getGrade() <= getGradeToSign()) {
            setSign(true);
            return true;
        }
        else {
            std::cerr << bureaucrat.getName() << " cannot sign " << _name << " because their grade is too low." << std::endl;
            return false;
        }
        return 0;
}

void AForm::setGradeToSign(unsigned int grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
    setGradeToSign(grade);
}

void AForm::setGradeToExecute(unsigned int grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
    setGradeToExecute(grade);
}

void AForm::setSign(bool isSigned) {
    _isSigned = isSigned;
}

unsigned int AForm::getGradeToSign() const {
    return _gradeToSign;
}

unsigned int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char *AForm::FormNotSigned::what() const throw() {
    return "Form is not signed!";
}

bool AForm::getSign() const {
    return _isSigned;
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
    os << "AForm Name: " << form.getName() 
       << ", Signed: " << (form.getSign() ? "Yes" : "No") 
       << ", Grade to Sign: " << form.getGradeToSign() 
       << ", Grade to Execute: " << form.getGradeToExecute();
    return os;
}
