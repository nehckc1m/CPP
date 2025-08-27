#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
    private:
        const std::string _name;
        bool _isSigned;
        const unsigned int _gradeToSign;
        const unsigned int _gradeToExecute;
        void setGradeToSign(unsigned int grade);
        void setGradeToExecute(unsigned int grade);
        void setSign(bool isSigned);
    public:
        AForm();
        AForm(const AForm &copy);
        AForm(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute);
        virtual ~AForm();
        AForm &operator=(const AForm &copy);
        virtual void execute(Bureaucrat const &executor) const = 0; // Pure virtual function
        const std::string &getName() const;
        bool beSigned(const Bureaucrat &bureaucrat);
        unsigned int getGradeToSign() const;
        unsigned int getGradeToExecute() const;
        bool getSign() const;
        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class FormNotSigned : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};
std::ostream &operator<<(std::ostream &os, const AForm &form);
#endif 