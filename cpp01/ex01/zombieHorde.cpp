#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name)
{
	if (n < 1)
	{
		std::cout << "u call this a horde?? put a bigger number." << std::endl;
		return (NULL);
	}
	
	Zombie *horde = new Zombie[n];
	if (!horde)
	{
		std:;cout << "Allocation failed\n" << std::endl;
		return (NULL);
	}
	for (int i = 0; i < n ; i++)
		horde[i].setName(name);
	return (horde);
}
