#include <string>

class Harl
{
private:
    void debug();
    void info();
    void warning();
    void error();
public:
    Harl(/* args */);
    ~Harl();
    void complain(std::string level);
    int getLevel(std::string level);
};