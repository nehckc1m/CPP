#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <climits>
#include <iostream>
#include <iterator>
#include <list>




class Span {
    private:
        Span();
        std::vector<int> _numbers;
    public:
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int num);
        int shortestSpan() const;
        int longestSpan() const;

        void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
            if (std::distance(begin, end) + _numbers.size() > _numbers.capacity())
                throw SpanFullException();
            _numbers.insert(_numbers.end(), begin, end);
        }

         class NotEnoughNumbersException : public std::exception {
            public:
                const char* what() const throw() {
                    return "Not enough numbers in Span, must be 2 numbers at least";
            }
        };

        class SpanFullException : public std::exception {
            public:
                const char* what() const throw() {
                    return "Span is full";
            }
        };

};