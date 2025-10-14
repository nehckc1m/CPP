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

    Span sp2 = Span(10000);
    std::cout << "Shortest Span in large Span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest Span in large Span: " << sp2.longestSpan() << std::endl;

    Span sp3 = Span(3);
    try{
        sp3.addRange(1, 50); // This should throw an exception
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}