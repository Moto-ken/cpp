
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("default") {
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    std::cout << "ScavTrap " << name << " is created" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    std::cout << "ScavTrap " << name << " is created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        this->hit_points = 100;
        this->energy_points = 50;
        this->attack_damage = 20;
    }
    std::cout << "ScavTrap assignment operator called" << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << name << " is destroyed" << std::endl;
}

// over ride
void ScavTrap::attack(const std::string& target) {
    if (energy_points == 0 || hit_points == 0) {
        std::cout << "ScavTrap " << name << " cannot attack" << std::endl;
        return;
    }
    energy_points--;
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing "
              << attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
    if (hit_points <= 0) return;
    if (amount >= hit_points)
        hit_points = 0;
    else
        hit_points -= amount;
    std::cout << "ScavTrap " << name << " takes " << amount << " damage!"
              << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
    if (energy_points == 0 || hit_points == 0) {
        std::cout << "ScavTrap " << name << " cannot repair" << std::endl;
        return;
    }
    energy_points--;
    hit_points += amount;
    std::cout << "ScavTrap " << name << " is repaired for " << amount
              << " hit points!" << std::endl;
}

void ScavTrap::guardGate() {
    if (energy_points <= 0 || hit_points == 0) {
        std::cout << "ScavTrap " << name << " cannot guardgate mode"
                  << std::endl;
        return;
    }
    energy_points--;
    std::cout << "ScavTrap " << name << " is chenged Gate keeper mode."
              << std::endl;
}
