#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <climits>
#include <iostream>
#include <iterator>



class Span : public std::vector<int> {
    private:
        unsigned int _N;
    public:
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int num);
        int shortestSpan() const;
        int longestSpan() const;

        template <typename iterator>
        void addRange (iterator begin, iterator end) {
            for (iterator it = begin; it != end; ++it) {
                if (std::distance(begin, end) + this->size() >= _N)
                    throw (std::out_of_range("not enough space in Span"));
                this->insert(this->end(), begin, end);
            }
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