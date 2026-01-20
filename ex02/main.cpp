#include "MutantStack.hpp"

void printSeparator(const std::string& title) {
    std::cout << "\n==============================" << std::endl;
    std::cout << title << std::endl;
    std::cout << "==============================" << std::endl;
}
void testBasicFunctionality() {
    printSeparator("TEST: Basic Functionality");
    
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top element: " << mstack.top() << std::endl;
    
    mstack.pop();
    
    std::cout << "Size after pop: " << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    std::cout << "\nIterating through MutantStack:" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::stack<int> s(mstack);
    std::cout << "\nCopied to std::stack successfully" << std::endl;

}

void testListComparison() {
    printSeparator("TEST: Comparison with std::list");
    
    std::cout << "--- MutantStack output ---" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::cout << "\n--- std::list output ---" << std::endl;
    std::list<int> list;
    list.push_back(5);
    list.push_back(17);
    std::cout << list.back() << std::endl;
    list.pop_back();
    std::cout << list.size() << std::endl;
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);
    
    std::list<int>::iterator lit = list.begin();
    std::list<int>::iterator lite = list.end();
    ++lit;
    --lit;
    while (lit != lite) {
        std::cout << *lit << std::endl;
        ++lit;
    }
}

void testReverseIterator() {
    printSeparator("TEST: Reverse Iterator");
    
    MutantStack<int> mstack;
    for (int i = 1; i <= 5; i++)
        mstack.push(i * 10);
    
    std::cout << "Forward iteration:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    std::cout << "\nReverse iteration:" << std::endl;
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
        std::cout << *rit << " ";
    std::cout << std::endl;
}

void testCopyConstructor() {
    printSeparator("TEST: Copy Constructor");
    
    MutantStack<int> mstack;
    mstack.push(42);
    mstack.push(21);
    mstack.push(84);
    
    MutantStack<int> copy(mstack);
    
    std::cout << "Original stack:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    std::cout << "\nCopied stack:" << std::endl;
    for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    copy.push(100);
    std::cout << "\nAfter adding 100 to copy:" << std::endl;
    std::cout << "Original size: " << mstack.size() << std::endl;
    std::cout << "Copy size: " << copy.size() << std::endl;
}

int main() {
    testBasicFunctionality();
    testListComparison();
    testReverseIterator();
    testCopyConstructor();

    printSeparator("All tests completed");
    
    return 0;
}

//  int main()
//  {
//     MutantStack<int> mstack;
//     mstack.push(5);
//     mstack.push(17);

//     std::cout << mstack.top() << std::endl;
//     mstack.pop();
//     std::cout << mstack.size() << std::endl;
//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
//     //[...]
//     mstack.push(0);
//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();
//     ++it;
//     --it;
//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }
//     //std::stack<int> s(mstack);
//     //s.push(42);
//     //std::cout << s.top() << std::endl;

//     std::cout << "-----" << std::endl;
//     std::cout << "List test" << std::endl;
//     std::list<int> lst;
//     lst.push_back(5);
//     lst.push_back(17);
//     std::cout << lst.back() << std::endl;
//     lst.pop_back();
//     std::cout << lst.size() << std::endl;
//     lst.push_back(3);
//     lst.push_back(5);
//     lst.push_back(737);
//     //[...]
//     lst.push_back(0);
//     std::list<int>::iterator lit = lst.begin();
//     std::list<int>::iterator lite = lst.end();
//     ++lit;
//     --lit;
//     while (lit != lite)
//     {
//         std::cout << *lit << std::endl;
//         ++lit;
//     }
//     std::cout << "-----" << std::endl;
//     std::cout << "stack test" << std::endl;
//     std::stack<int> s;
//     s.push(5);
//     s.push(17);
//     std::cout << s.top() << std::endl;
//     s.pop();
//     std::cout << s.size() << std::endl;
//     s.push(3);
//     s.push(5);
//     s.push(737);
//     //[...]
//     s.push(0);
//     // No iterators in std::stack  

//     return 0;
//  }