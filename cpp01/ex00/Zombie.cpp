#include "Zombie.hpp"

Zombie::Zombie(std::string str) : _name(str) {}

Zombie::~Zombie() {
	std::cout << _name << " is destroyed." << std::endl;
}

void Zombie::announce() {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
	_name = name;
	std::cout << "The soil is moving!\n";
	std::cout << _name << " is rising..." << std::endl;
}
