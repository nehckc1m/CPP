#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
	private:
		std::string _name;

	public:
		Zombie();
		~Zombie();
		void announce();
		void setName(std::string _name);
};

Zombie* zombieHorde(int _n, std::string _name);

#endif


