
#include "Weapon.hpp"

Weapon::Weapon(std::string type) : weapon(type) {}

Weapon::~Weapon() {}

void Weapon::setType(std::string type) { weapon = type; }

std::string Weapon::getType(void) const { return (weapon); }
