#include "Zombie.hpp"

int	main()
{
	Zombie *horde;
	int	n;
	n = 5;

	horde = zombieHorde(n, "minions");
	if (!horde)
	{
		return (0);
	}
	for (int i = 0; i < n ; i++)
		horde[i].announce();
	delete[] horde;
	return 0;
}

