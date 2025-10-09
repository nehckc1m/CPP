#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    std::cout << "----------------------------------------" << std::endl;
    Array<int>();
    Array<int> numbers(MAX_VAL);
    std::cout << "----------------------------------------" << std::endl;
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    std::cout << "----------------------------------------" << std::endl;
    std::cout << mirror[100] << std::endl;
    std::cout << numbers[100] << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        //mirror[0] = 0;
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "TRYNGN-------------: " << std::endl;
        numbers[740] = 110;
        std::cout << "numbers[740] : " << numbers[740] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    delete [] mirror;

    return 0;
}