#include "BitcoinExchange.hpp"

int main (int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    BitcoinExchange btcExchange;
    if (!btcExchange.loadData("data.csv")) {
        std::cerr << "Failed to load data file." << std::endl;
        return 1;
    }
    btcExchange.loadData("data.csv");
    btcExchange.processInput(argv[1]);

    return 0;
}