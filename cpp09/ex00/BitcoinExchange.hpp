#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>

class BitcoinExchange {
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);

        bool loadData(const std::string& filename);
        std::string findClosestDate(const std::string& date);
        void processInput(const std::string& filename);
        bool isValidDate(const std::string& date);
        float getValue(const std::string& date);
        int isValidValue(const std::string& valueStr);
        int checkFile(const std::string& filename);
    private:
        std::map<std::string, double> _priceData; // date to value mapping
};