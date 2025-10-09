#pragma once
#include <cstddef>
#include <string>
#include <stdexcept>
#include <iostream>
#include <cstdlib>

template <typename T>
class Array {
    private:
        T* _data;
        size_t _size;
    public:
        Array() {
            _data = NULL;
            _size = 0;
        }
        Array(unsigned int n) {
            _data = new T[n];
            _size = n;
            for (size_t i = 0; i < n; i++) {
                _data[i] = T();
            }
        }
        Array(const Array& other)  {
            _size = other._size;
            _data = new T[_size];
            for (size_t i = 0; i < _size; i++) {
                _data[i] = other._data[i];
            }
        }
        Array& operator=(const Array& other) {
            if (this != &other) {
                delete[] _data;
                _size = other._size;
                _data = new T[_size];
                for (size_t i = 0; i < _size; i++) {
                    _data[i] = other._data[i];
                }
            }
            return *this;
        }
        ~Array() {
            delete[] _data;
        }
        T& operator[](size_t index) {
            if (index >= _size) {
                throw IndexOutOfBoundsException();
            }
            return _data[index];
        }
        class IndexOutOfBoundsException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Index out of bounds";
                }
        };
};