#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    Base* obj = generate();
    if (!obj) {
        std::cerr << "Failed to generate object" << std::endl;
        return 1;
    }
    Base *obj2 = NULL;

    std::cout << "Identifying using pointer:" << std::endl;
    identify(obj);

    std::cout << "Identifying using reference:" << std::endl;
    identify(*obj);

    std::cout << "Identifying using pointer:" << std::endl;
    identify(obj2);

    std::cout << "Identifying using reference:" << std::endl;
    identify(*obj2);
    delete obj;
    return 0;
}