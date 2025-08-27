#ifndef BUREACREAT_HPP
#define BUREACREAT_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>

class AForm;

class Bureaucrat {

    private: 
            const std::string _name;
            unsigned int _grade;
            void        setGrade(unsigned int grade);
    public:
            Bureaucrat();
            Bureaucrat(const Bureaucrat &copy);
            Bureaucrat(const std::string &name, unsigned int grade);
            ~Bureaucrat();
            Bureaucrat &operator=(const Bureaucrat &copy);
            const std::string &getName() const;
            unsigned int getGrade() const;
            void incrementGrade();
            void decrementGrade();
            void signForm(AForm &f) const;
            void executeForm(const AForm &form) const;

            class GradeTooHighException : public std::exception {
                public:
                    virtual const char *what() const throw();
            };
            class GradeTooLowException : public std::exception {
                public:
                    virtual const char *what() const throw();
            };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);
#endif