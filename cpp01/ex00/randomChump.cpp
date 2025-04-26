#include "Zombie.hpp"

void randomChump(std::string _name)
{
	Zombie* zombo = newZombie(_name);
	zombo->setName(_name);
	zombo->announce();
	delete zombo;
}
