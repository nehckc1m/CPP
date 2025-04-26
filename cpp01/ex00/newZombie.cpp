#include "Zombie.hpp"

Zombie* newZombie(std::string _name){
	Zombie *zombo = new Zombie(_name);
	return (zombo);
}
