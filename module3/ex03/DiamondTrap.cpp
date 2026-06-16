
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("default_clap_name"), ScavTrap(), FragTrap(), name("default") {
    hit_points = 100;
    energy_points = 50;
    attack_damage = 30;
    std::cout << "DiamondTrap " << name << " is created" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string diamondName)
    : ClapTrap(diamondName + "_clap_name"),
      ScavTrap(diamondName),
      FragTrap(diamondName),
      name(diamondName) {
    hit_points = 100;
    energy_points = 50;
    attack_damage = 30;
    std::cout << "DiamondTrap " << name << " is created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other) {
    *this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
        name = other.name;
        hit_points = other.hit_points;
        energy_points = other.energy_points;
        attack_damage = other.attack_damage;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << name << " is destroyed" << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "ClapTrap name is " << ClapTrap::name << std::endl;
    std::cout << "DiamondTrap name is " << name << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount) {
    if (hit_points <= 0) return;
    if (amount >= hit_points)
        hit_points = 0;
    else
        hit_points -= amount;
    std::cout << "DiamondTrap " << name << " takes " << amount << " damage!"
              << std::endl;
}

void DiamondTrap::beRepaired(unsigned int amount) {
    if (energy_points == 0 || hit_points == 0) {
        std::cout << "DiamondTrap " << name << " cannot repair" << std::endl;
        return;
    }
    energy_points--;
    hit_points += amount;
    std::cout << "DiamondTrap " << name << " is repaired for " << amount
              << " hit points!" << std::endl;
}

