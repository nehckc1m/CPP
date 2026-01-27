#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cctype>
#include <stdexcept>
#include <cstdlib>
#include <utility>

class RPN {
    public:
        RPN();
        ~RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        bool isValidInput(const std::string& expression);
        void processing(const std::string& expression);
    private:
        std::stack<int> _stack;
        bool isOperator(char c);
        int performOperation(int a, int b, char op);
};