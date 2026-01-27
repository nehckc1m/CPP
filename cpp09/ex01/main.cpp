#include "RPN.hpp"


int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " \"RPN_expression\"" << std::endl;
        return 1;
    }

    RPN rpnCalculator;
    if (!rpnCalculator.isValidInput(argv[1])) {
        std::cerr << "Error: Invalid input expression." << std::endl;
        return 1;
    } 
    rpnCalculator.processing(argv[1]);
    return 0;
}