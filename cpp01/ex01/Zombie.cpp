#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie() {
	std::cout << _name << " is destroyed." << std::endl;
}

void Zombie::announce() {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string _name) {
	this->_name = _name;
	std::cout << "The soil is moving!\n";
	std::cout << this->_name << " is rising..." << std::endl;
}
