#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
    }
    return *this;
}

bool BitcoinExchange::loadData(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 0;
    }
    std::string line;
    bool firstLine = true;
    while (std::getline(file, line)) {
        if (firstLine) {
            firstLine = false;
            continue;
        }
        size_t pos = line.find(',');
        if (pos == std::string::npos) {
            continue;
        }
        std::string date = line.substr(0, pos);
        std::string valueStr = line.substr(pos + 1);
        _priceData[date] = std::atof(valueStr.c_str());
        //std::cout << "Loaded data for date: " << _priceData[date] << std::endl;
    }
    file.close();
    return 1;
}

std::string BitcoinExchange::findClosestDate(const std::string& date) {
    std::map<std::string, double>::iterator it = _priceData.lower_bound(date);
    if (it != _priceData.end() && it->first == date) {
        return it->first;
    }
    if (it == _priceData.begin()) {
        return it->first;
    }
    --it;
    return it->first;
}

bool BitcoinExchange::isValidDate(const std::string& date) {
    if (date.length() - 1 != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }
    
    for (size_t i = 0; i < date.length() - 1; ++i) {
        if (i == 4 || i == 7) 
            continue;
        if (!isdigit(date[i])) {
            return false;
        }
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    //std::cout << "Parsed date - Year: " << year << ", Month: " << month << ", Day: " << day << std::endl;

    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;
    if (month == 2) {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (isLeap ? 29 : 28))
            return false;
    }

    return true;
}

void BitcoinExchange::processInput(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        size_t pos = line.find('|');
        if (pos == std::string::npos) {
            std::cerr << "Error: Invalid line format: " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, pos);
        std::string valueStr = line.substr(pos + 1);
        double value = std::atof(valueStr.c_str());

        if (isValidDate(date) == false) {
            std::cerr << "Error: Invalid date format: " << date << std::endl;
            continue;
        }
        if (value < 0) {
            std::cerr << "Error: not a positive value: " << value << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cerr << "Error: too large a value: " << value << std::endl;
            continue;
        }
        value = _priceData[findClosestDate(date)] * value;
        std::cout << date << "with value:" << valueStr << " = " << value << std::endl;
    }
    file.close();
}