#include "Form.hpp"
#include <stdexcept>


Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
    std::cout << "Default constructor called for Form: " << _name << std::endl;
}
Form::Form(const Form &copy) : _name(copy._name), _isSigned(copy._isSigned), 
                               _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {
    std::cout << "Copy constructor called for Form: " << _name << std::endl;
}

Form::Form(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute) : _name(name), _isSigned(false), 
    _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    std::cout << "Parameterized constructor called for Form: " << _name << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    } else if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

Form::~Form() {
    std::cout << "Destructor called for Form: " << _name << std::endl;
}

Form &Form::operator=(const Form &copy) {
    if (this != &copy) {
        setSign(copy._isSigned);
        setGradeToSign(copy._gradeToSign);
        setGradeToExecute(copy._gradeToExecute);
    }
    return *this;
}

const std::string &Form::getName() const {
    return _name;
}

bool Form::beSigned(const Bureaucrat &bureaucrat){
        
    if (_isSigned) {
        std::cerr << "Form " << _name << " is already signed." << std::endl;
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

void Form::setGradeToSign(unsigned int grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
    setGradeToSign(grade);
}

void Form::setGradeToExecute(unsigned int grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
    setGradeToExecute(grade);
}

void Form::setSign(bool isSigned) {
    _isSigned = isSigned;
}

unsigned int Form::getGradeToSign() const {
    return _gradeToSign;
}

unsigned int Form::getGradeToExecute() const {
    return _gradeToExecute;
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

bool Form::getSign() const {
    return _isSigned;
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
    os << "Form Name: " << form.getName() 
       << ", Signed: " << (form.getSign() ? "Yes" : "No") 
       << ", Grade to Sign: " << form.getGradeToSign() 
       << ", Grade to Execute: " << form.getGradeToExecute();
    return os;
}
