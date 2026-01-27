#include "PmergeMe.hpp"


int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: No input provided." << std::endl;
        return 1;
    }

    PmergeMe pmergeMe;
    if (!pmergeMe.processInput(argc, argv))
        return 1;
    pmergeMe.sortAndDisplay();
    // try {
    //     pmergeMe.processInput(argc, argv);
    //     pmergeMe.sortAndDisplay();
    // } catch (const std::exception& e) {
    //     std::cerr << e.what() << std::endl;
    //     return 1;
    // }

    return 0;
}