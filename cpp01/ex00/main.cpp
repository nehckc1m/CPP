#include "Zombie.hpp"

int main()
{
	std::string name;
	std::cout << "Name of this zombie: " << std::endl;
	std::cin >> name;
	if (std::cin.eof())
	{
		std::cout << "byeeee..." << std::endl;
		return 0;
	}
	randomChump(name);
	return 0;
}
