#include "Harl.hpp"
#include <iostream>
int main(int argc, char const *argv[])
{
    if (argc == 2)
    {
        std::string level = argv[1];
        Harl harl;
        harl.complain(level);
    }
    else
    {
        std::cerr << "Usage: " << argv[0] << " <level>" << std::endl;
        return 1;
    }
    return 0;
}
