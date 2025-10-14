#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {}
Span::Span(const Span& other) : _N(other._N) {}
Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _N = other._N;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int num) {
    if (_N == _numbers.size())
        throw SpanFullException();
    _numbers.push_back(num);
}

int Span::shortestSpan() const {
    if (this->_N() < 2)
        throw NotEnoughNumbersException();
    std::vector<int> vec = _numbers;
    std::sort(vec.begin(), vec.end());
    int minSpan = INT_MAX;
    for (size_t i = 1; i < vec.size(); ++i) {
        int span = vec[i] - vec[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw NotEnoughNumbersException();
    int minNum = *std::min_element(_numbers.begin(), _numbers.end());
    int maxNum = *std::max_element(_numbers.begin(), _numbers.end());
    return maxNum - minNum;
}