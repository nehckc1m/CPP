#pragma once
#include <cstddef>

template <typename T, typename F>
void iter(T *adress, size_t length, F func) {
    for (size_t i = 0; i < length; i++) {
        func(adress[i]);
    }    
}
