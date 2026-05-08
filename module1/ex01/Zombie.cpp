
#include "Zombie.hpp"

Zombie::Zombie(void) : name("unknown") {
    std::cout << "create zombie" << std::endl;
}

Zombie::~Zombie(void) { std::cout << name << " deleted" << std::endl; }

void Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string zom_name) { name = zom_name; }
