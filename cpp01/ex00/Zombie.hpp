#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
	private:
		std::string _name;

	public:
		Zombie(std::string _name);
		~Zombie();

		void announce();
		void setName(std::string _name);
};

void randomChump(std::string _name);
Zombie* newZombie(std::string _name);

#endif


