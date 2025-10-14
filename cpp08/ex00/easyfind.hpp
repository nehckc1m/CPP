#pragma once

#include <algorithm>
#include <stdexcept>
#include <iostream>
template <typename T>
typename T::iterator easyfind(T &container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw NotFoundException();
    }
    return it;
}

class NotFoundException : public std::exception {
   public:
    const char* what() const throw() {
        return "Value not found in container";
    }
};