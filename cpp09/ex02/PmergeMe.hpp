#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <ctime>
#include <sys/time.h>

struct IndexedPair {
    size_t index;
    int first;
    int second;
};
class PmergeMe {
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        bool processInput(int argc, char** argv);
        void sortAndDisplay();
        
    private:
        std::vector<int> _vectorData;
        std::deque<int> _dequeData;
        template <typename C>
        C generateJacobsthalNumbers(size_t n);
        //std::vector<size_t> generateJacobsthalNumbers(size_t n);
        template <typename C>
        void mergeInsertSort(C& data);
        void mergeInsertSortVector(std::vector<int>& data);
        //void     mergeInsertSortDeque(std::deque<int>& data);
        //bool isSorted(const std::vector<int>& data);
        template <typename C>
        C SortingMain(C& data);
        int FindPairIndex(std::vector<int> main, const std::vector<struct IndexedPair>& pairs, int value);
};