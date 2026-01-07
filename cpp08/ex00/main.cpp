#include "easyfind.hpp"
#include <vector>
#include <list>

int main () {
    std::vector<int> vec;
    std::list<int> lst;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);

    try{
        std::vector<int>::iterator it_vec = easyfind(vec, 3);
        std::cout << "Found in vector: " << *it_vec << std::endl;
        std::cout << "-----------" << std::endl;
        //easyfind(vec, 5);
        std::list<int>::iterator it_lst = easyfind(lst, 40);
        std::cout << "Found in list: " << *it_lst << std::endl;
        std::cout << "-----------" << std::endl;
        easyfind(vec, 50);
    } catch (const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}