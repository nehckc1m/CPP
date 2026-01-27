#include "PmergeMe.hpp"


PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) : _vectorData(other._vectorData), _dequeData(other._dequeData) {}
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vectorData = other._vectorData;
        _dequeData = other._dequeData;
    }
    return *this;
}

template <typename C>
C PmergeMe::generateJacobsthalNumbers(size_t n) {
    C order;
    order.push_back(0);
    if (n == 0) 
        return order;
    order.push_back(1);
    for (size_t i = 2; i <= n; ++i) {
        size_t next = order[i - 1] + 2 * order[i - 2];
        order.push_back(next);
    }
    return order;
}

// std::vector<size_t> PmergeMe::generateJacobsthalNumbers(size_t n) {
//     std::vector<size_t> order;
//     order.push_back(0);
//     if (n == 0) 
//         return order;
//     order.push_back(1);
//     for (size_t i = 2; i <= n; ++i) {
//         size_t next = order[i - 1] + 2 * order[i - 2];
//         order.push_back(next);
//     }
//     return order;
// }

void PmergeMe::sortAndDisplay() {
    
    struct timeval start, end;
    std::cout << "Before sorting: ";
    for (size_t i = 0; i < _vectorData.size(); ++i) {
        std::cout << _vectorData[i] << " ";
    }
    std::cout << std::endl;

    gettimeofday(&start, NULL);
    mergeInsertSort(_vectorData);
    gettimeofday(&end, NULL);

    double duration = ((end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec)) / 1000.0;

    std::cout << "After sorting: ";
    for (size_t i = 0; i < _vectorData.size(); ++i) {
        std::cout << _vectorData[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Time taken to sort vector: " << duration << " ms " << std::endl;

    gettimeofday(&start, NULL);
    mergeInsertSort(_dequeData);
    gettimeofday(&end, NULL);

    duration = ((end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec)) / 1000.0;
    //  std::cout << "After sorting: ";
    // for (size_t i = 0; i < _dequeData.size(); ++i) {
    //     std::cout << _dequeData[i] << " ";
    // }
    //std::cout << std::endl;
    std::cout << "Time taken to sort deque: " << duration << " ms " << std::endl;
}

// bool PmergeMe::isSorted(const std::vector<int>& data) {
//     for (size_t i = 1; i < data.size(); ++i) {
//         if (data[i - 1] > data[i]) {
//             return false;
//         }
//     }
//     return true;
// }
template <typename C>
C PmergeMe::SortingMain(C& data) {
    std::sort(data.begin(), data.end());
    return data;
}

// void PmergeMe::mergeInsertSortVector(std::vector<int>& data) {
//     if (data.size() <= 1){
//         _vectorData = data;
//         return;
//     }

//     int straggler = -1;
//     bool hasStraggler = false;
//     if (data.size() % 2 != 0) {
//         straggler = data.back();
//         data.pop_back();
//         hasStraggler = true;
//     }
//     std::vector<IndexedPair> pairs;

//     for (size_t i = 0; i < data.size(); i += 2) {
//         IndexedPair p;
//         p.index = i / 2;
//         if (data[i] < data[i + 1]) {
//             p.first = data[i + 1];
//             p.second = data[i];
//         } else {
//             p.first = data[i];
//             p.second = data[i + 1];
//         }
//         pairs.push_back(p);
//     }

//     std::vector<int> main;
//     for (size_t i = 0; i < pairs.size(); ++i) {
//         main.push_back(pairs[i].first);
//     }
//     main = SortingMain(main);
//     std::vector<int> pending;
//     for (size_t i = 0; i < main.size(); ++i) {
//         for (size_t j = 0; j < pairs.size(); ++j) {
//             if (pairs[j].first == main[i]) {
//                 pending.push_back(pairs[j].second);
//                 break;
//             }
//         }
//     }
//     // std::cout << "main: ";
//     // for (size_t i = 0; i < main.size(); ++i) {
//     //     std::cout << main[i] << " ";
//     // }
//     // std::cout << std::endl;
//     // std::cout << "Pending: ";
//     // for (size_t i = 0; i < pending.size(); ++i) {
//     //     std::cout << pending[i] << " ";
//     // }
//     // std::cout << std::endl;

//     main.insert(main.begin(), pending[0]);
//     // std::cout << "--------------" << std::endl;
//     std::vector<size_t> jacobsthal = generateJacobsthalNumbers(pending.size());
//     //size_t pos = 0;
//     size_t i = 1;
//     //std::cout << "pending size: " << pending.size() - 1 << std::endl;
//     while (i < pending.size() - 1 && jacobsthal[i] < pending.size()) {
//         //size_t indexJ = i;
//         size_t pos = jacobsthal[i + 1];
//         while (pos > pending.size() - 1)
//             pos--;
//         // std::cout << "Inserting pending index: " << pos << " value: " << pending[pos] << std::endl;
//         // std::cout << "i : " << i << " jacobsthal[i]: " << jacobsthal[i] << " jacobsthal[i - 1]: " << jacobsthal[i -1] << std::endl;
//         while (pos >= jacobsthal[i] && pos > jacobsthal[i - 1] && pos < pending.size()) {
//             int j = main.size() / 2;
//             while (pending[pos] < main[j] && j > 0) {
//                 j--;
//             }
//             while (pending[pos] > main[j] && j < static_cast<int>(main.size())) {
//                 j++;
//             }
//             if (pending[pos] != -1)
//                 main.insert(main.begin() + j, pending[pos]);
//             pending[pos] = -1;
//             pos--;
//         }
//         i++;
//     }
//     if (hasStraggler) {
//         int j = main.size() - 1;
//         while (straggler < main[j] && j > 0) {
//             j--;
//         }
//         while (j > 0 && straggler > main[j]) {
//             j++;
//         }
//         main.insert(main.begin() + j, straggler);
//     }

//     // std::cout << "after sorting: ";
//     // for (size_t i = 0; i < main.size(); ++i) {
//     //     std::cout << main[i] << " ";
//     // }
//     // std::cout << std::endl;
//     this->_vectorData = main;
// }

// int PmergeMe::FindPairIndex(std::vector<int> main, const std::vector<IndexedPair>& pairs, int value) {
//    std::vector<IndexedPair> indexValuePairs;
//     for (size_t i = 0; i < pairs.size(); ++i) {
//         if (pairs[i].second == value) {
//             indexValuePairs.push_back(pairs[i]);
//         }
//     }
//     for(size_t i = 0; i < main.size(); ++i) {
//         if (main[i] == indexValuePairs[0].first) {
//                 return i;
//             }
//         }
//     return -1; // Not found
// }

template <typename C> 
void PmergeMe::mergeInsertSort(C& data) {
    if (data.size() <= 1){
        return;
    }

    int straggler = -1;
    bool hasStraggler = false;
    if (data.size() % 2 != 0) {
        straggler = data.back();
        data.pop_back();
        hasStraggler = true;
    }
    std::vector<IndexedPair> pairs;

    for (size_t i = 0; i < data.size(); i += 2) {
        IndexedPair p;
        p.index = i / 2;
        if (data[i] < data[i + 1]) {
            p.first = data[i + 1];
            p.second = data[i];
        } else {
            p.first = data[i];
            p.second = data[i + 1];
        }
        pairs.push_back(p);
    }

    C main;
    for (size_t i = 0; i < pairs.size(); ++i) {
        main.push_back(pairs[i].first);
    }
    main = SortingMain(main);
    C pending;
    for (size_t i = 0; i < main.size(); ++i) {
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (pairs[j].first == main[i]) {
                pending.push_back(pairs[j].second);
                break;
            }
        }
    }
    if (pending.empty()) {
        data = main;
        return;
    }
    // std::cout << "main: ";
    // for (size_t i = 0; i < main.size(); ++i) {
    //     std::cout << main[i] << " ";
    // }
    // std::cout << std::endl;
    // std::cout << "Pending: ";
    // for (size_t i = 0; i < pending.size(); ++i) {
    //     std::cout << pending[i] << " ";
    // }
    // std::cout << std::endl;

    main.insert(main.begin(), pending[0]);

    // if (pending.size() == 1) {  
    //     if (hasStraggler) {
    //         int j = 0;
    //         while (j < static_cast<int>(main.size()) && straggler > main[j]) {
    //             j++;
    //         }
    //         main.insert(main.begin() + j, straggler);
    //     }
    //     data = main;
    //     return;
    // }
    // std::cout << "--------------" << std::endl;
    C jacobsthal = generateJacobsthalNumbers<C>(pending.size());
    //size_t pos = 0;
    size_t i = 1;
     //std::cout << "pending size: " << pending.size() - 1 << std::endl;
     while (i <= pending.size() - 1 && jacobsthal[i] < (static_cast<int>(pending.size()))) {
        //size_t indexJ = i;
        size_t pos = jacobsthal[i + 1];
        while (pos > pending.size() - 1)
            pos--;
        // std::cout << "Inserting pending index: " << pos << " value: " << pending[pos] << std::endl;
        // std::cout << "i : " << i << " jacobsthal[i]: " << jacobsthal[i] << " jacobsthal[i - 1]: " << jacobsthal[i -1] << std::endl;
        while (pos >= (static_cast<size_t>(jacobsthal[i])) && pos > (static_cast<size_t>(jacobsthal[i - 1])) && pos < pending.size()) {
            int j = main.size() / 2;
            while (pending[pos] < main[j] && j > 0) {
                j--;
            }
            while (pending[pos] > main[j] && j < static_cast<int>(main.size())) {
                j++;
            }
            if (pending[pos] != -1)
                main.insert(main.begin() + j, pending[pos]);
            pending[pos] = -1;
            pos--;
        }
        i++;
    }

    if (hasStraggler) {
        int j = main.size() / 2;
        while (straggler < main[j] && j > 0) {
            j--;
        }
        while (straggler > main[j] && j < static_cast<int>(main.size())) {
            j++;
        }
        main.insert(main.begin() + j, straggler);
    }
    data = main;
}

// void PmergeMe::mergeInsertSortDeque(std::deque<int>& data) {
//     if (data.size() <= 1){
//         _dequeData = data;
//         return;
//     }

//     int straggler = -1;
//     bool hasStraggler = false;
//     if (data.size() % 2 != 0) {
//         straggler = data.back();
//         data.pop_back();
//         hasStraggler = true;
//     }
    
//     std::deque<IndexedPair> pairs;
//     for (size_t i = 0; i < data.size(); i += 2) {
//         IndexedPair p;
//         p.index = i / 2;
//         if (data[i] < data[i + 1]) {
//             p.first = data[i + 1];
//             p.second = data[i];
//         } else {
//             p.first = data[i];
//             p.second = data[i + 1];
//         }
//         pairs.push_back(p);
//     }

//     std::deque<int> main;
//     for (size_t i = 0; i < pairs.size(); ++i) {
//         main.push_back(pairs[i].first);
//     }
//     main = SortingMain(main);
//     std::deque<int> pending;
//     for (size_t i = 0; i < main.size(); ++i) {
//         for (size_t j = 0; j < pairs.size(); ++j) {
//             if (pairs[j].first == main[i]) {
//                 pending.push_back(pairs[j].second);
//                 break;
//             }
//         }
//     }

//     main.insert(main.begin(), pending[0]);
//     std::vector<size_t> jacobsthal = generateJacobsthalNumbers(pending.size());
//     size_t i = 1;
//     while (i < pending.size() - 1 && jacobsthal[i] < pending.size()) {
//         size_t pos = jacobsthal[i + 1];
//         while (pos > pending.size() - 1)
//             pos--;
//         while (pos >= jacobsthal[i] && pos > jacobsthal[i - 1] && pos < pending.size()) {
//             int j = main.size() / 2;
//             while (pending[pos] < main[j] && j > 0) {
//                 j--;
//             }
//             while (pending[pos] > main[j] && j < static_cast<int>(main.size())) {
//                 j++;
//             }
//             if (pending[pos] != -1)
//                 main.insert(main.begin() + j, pending[pos]);
//             pending[pos] = -1;
//             pos--;
//         }
//         i++;
//     }
//     if (hasStraggler) {
//         int j = main.size() - 1;
//         while (straggler < main[j] && j > 0) {
//             j--;
//         }
//         while (j > 0 && straggler > main[j]) {
//             j++;
//         }
//         main.insert(main.begin() + j, straggler);
//     }

//     _dequeData = main;
// }

bool PmergeMe::processInput(int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
        std::istringstream iss(argv[i]);
        int number;
        if (!(iss >> number)) {
           std::cerr << "Error: Invalid input '" << argv[i] << "'." << std::endl;
            return 0;
        }
        // Check for any extra characters after the number exmaple: "123abc"
        std::string extra;
        if (iss >> extra) {
            std::cerr << "Error: Invalid input '" << argv[i] << "'." << std::endl;
            return 0;
        }

        if (number < 0) {
            std::cerr << "Error: Negative numbers are not allowed '" << argv[i] << "'." << std::endl;
            return 0;
        }
        _vectorData.push_back(number);
        _dequeData.push_back(number);
    }
    return 1;
}