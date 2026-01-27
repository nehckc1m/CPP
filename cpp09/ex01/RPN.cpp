#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN& other) {
    *this = other;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _stack = other._stack;
    }
    return *this;
}

bool RPN::isValidInput(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;
    while (iss >> token) {
        if (token.length() == 1 && isOperator(token[0])) {
            continue;
        } else {
            for (size_t i = 0; i < token.length(); ++i) {
                if (!std::isdigit(token[i]) && !(i == 0 && (token[i] == '-' || token[i] == '+'))) 
                    return false;
                }
        }
    }
    return true;
}

void RPN::processing(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;
    while (iss >> token) {
        if (token.length() == 1 && isOperator(token[0])) {
            if (_stack.size() < 2) {
                std::cerr << "Error: Not enough operands for operation '" << token << "'" << std::endl;
                return;
            }
            int b = _stack.top(); 
            _stack.pop();
            int a = _stack.top(); 
            _stack.pop();
            int result = performOperation(a, b, token[0]);
            if (result == 0 && token[0] == '/') {
                std::cerr << "Error: Division by zero" << std::endl;
                return; 
            }
            //std::cout << "Performed operation: " << a << " " << token << " " << b << " = " << result << std::endl;
            _stack.push(result);
        } else {
            try {
                int value = std::atoi(token.c_str());
                _stack.push(value);
            } catch (const std::invalid_argument&) {
                std::cerr << "Error: Invalid token '" << token << "'" << std::endl;
                return;
            }
        }
    }
    if (_stack.size() == 1) {
        std::cout << "Result: " << _stack.top() << std::endl;
    } else {
        std::cerr << "Error: The stack has " << _stack.size() << " elements after evaluation." << std::endl;
    }
}

bool RPN::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::performOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) 
                return 0;
        return a / b;
    }
    return 0;
}