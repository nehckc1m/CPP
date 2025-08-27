#pragma once

#include "AForm.hpp"

#define ASCII_TREE \
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⢀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"\
"⠀⠀⠀⠀⢀⣀⠄⠠⠐⠐⠈⠀⠁⠒⠋⠁⠁⠁⠁⠁⠈⠈⠈⠀⢁⣁⡩⠇⠀⠀⠀⠀⠀⠀⠀⠀\n"\
"⠀⠀⢀⣀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠁⠁⠂⠄⡀⡀⠀⠀⠀⠀⠀⠀\n"\
"⢐⠋⠁⠀⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠑⢤⠀⠀⠀\n"\
"⠸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠒⠚⠄⡀⠀\n"\
"⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢣\n"\
"⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸\n"\
"⠀⠈⢦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠤⣤⠤⠼\n"\
"⢰⠊⠁⠀⠀⠀⠀⠀⡠⡻⣁⣁⣀⣀⠤⠤⠤⠒⠒⠒⠒⠒⠒⠒⠒⠒⢲⢀⠀⠀⠀⠀⠀⠀⠃⡀\n"\
"⠀⣇⠀⠀⢀⡀⡤⠊⠀⠇⠀⠀⠀⠀⢀⣤⡄⠀⠀⠀⠀⣤⡄⠀⠀⠀⢸⠀⠣⡀⠀⠀⠀⠀⠀⠡\n"\
"⠀⠈⠉⠉⠁⠀⠀⠀⢠⠁⠀⠀⠀⢠⢻⡿⡟⠀⠀⠀⢸⣿⣿⠀⠀⠀⢸⠀⠀⠣⠄⠤⠤⠄⠂⠚\n"\
"⠀⠀⠀⠀⠀⠀⠀⠀⡸⠀⠀⠀⠀⠈⠉⠉⢁⢠⠀⠀⠑⠚⠋⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"\
"⠀⠀⠀⠀⠀⠀⠀⢀⠆⠀⠀⠀⠀⠀⠀⠀⠀⠙⠷⠦⠤⠶⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"\
"⠀⠀⠀⠀⠀⠀⠀⠘⠒⠂⠒⠒⠂⠒⠤⠤⠤⢄⣀⣀⡀⠀⠀⠀⠀⠀⠘⡄⠀⠀⠀⠀⠀⠀⠀⠀\n"\
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠒⠒⠲⠤⠇⠀⠀⠀⠀⠀⠀⠀⠀\n"

class ShrubberyCreationForm : public AForm {
    public:
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &copy);
        virtual ~ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);

        virtual void execute(Bureaucrat const &executor) const;
        const std::string &getTarget() const;
    private:
        std::string _target;
};