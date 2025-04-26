#include "Weapon.hpp"

Weapon::Weapon(){}

const std::string& Weapon::getType()
{
	return _type;
}

void Weapon::setType(const std::string type)
{

	this->_type = type;
}

