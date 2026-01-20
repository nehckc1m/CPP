#include "Span.hpp"

int main() {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

    std::cout << "---------------------------" << std::endl;

    Span sp2 = Span(10000);
    std::vector<int> nums;
    for (int i = 0; i < 10000; ++i) {
        nums.push_back(i);
    }
    sp2.addRange(nums.begin(), nums.end()); // Adding numbers from 0 to 9999
    std::cout << "Shortest Span in large Span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest Span in large Span: " << sp2.longestSpan() << std::endl;

    std::cout << "---------------------------" << std::endl;

    Span sp3 = Span(3);
    try{
        sp3.addRange(nums.begin(), nums.end()); // This should throw an exception
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "---------------------------" << std::endl;

    Span sp4 = Span(1);
    try {
        sp4.addNumber(42);
        sp4.shortestSpan(); // This should throw an exception
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
     std::cout << "---------------------------" << std::endl;

    Span sp5 = Span(1);
    try {
        sp5.addNumber(42);
        sp5.addNumber(99); // This should throw an exception
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}