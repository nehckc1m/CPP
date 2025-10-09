#include "iter.hpp"
#include <iostream>
#include <string>

void printInt(int& x) {
    std::cout << x << " ";
}

void printString(const std::string& x) {
    std::cout << x << " ";
}

int main() {
    int tab[] = {0, 1, 2, 3, 4};
    std::string tab2[] = {"hello", "world", "!"};

    ::iter(tab, 5, printInt);
    std::cout << std::endl;
    ::iter(tab2, 3, printString);
    std::cout << std::endl;
    return 0;
}