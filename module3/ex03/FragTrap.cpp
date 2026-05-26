
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("default") {
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
    std::cout << "FragTrap " << name << " is created" << std::endl;
}

FragTrap::FragTrap(const std::string& fragName) : ClapTrap(fragName) {
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
    std::cout << "FragTrap " << fragName << " is created" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) ClapTrap::operator=(other);
    std::cout << "FragTrap assignment operator called" << std::endl;
    return (*this);
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << name << " is destroyed" << std::endl;
}

void FragTrap::highFivesGuys() {
    if (energy_points <= 0 || hit_points == 0) {
        std::cout << "FragTrap " << name << " cannot highfives" << std::endl;
        return;
    }
    energy_points--;
    std::cout << "FragTrap " << name << " requests high fives!" << std::endl;
}

// over ride
void FragTrap::attack(const std::string& target) {
    if (energy_points == 0 || hit_points == 0) {
        std::cout << "FragTrap " << name << " cannot attack" << std::endl;
        return;
    }
    energy_points--;
    std::cout << "FragTrap " << name << " attacks " << target << ", causing "
              << attack_damage << " points of damage!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
    if (hit_points <= 0) return;
    if (amount >= hit_points)
        hit_points = 0;
    else
        hit_points -= amount;
    std::cout << "FragTrap " << name << " takes " << amount << " damage!"
              << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
    if (energy_points == 0 || hit_points == 0) {
        std::cout << "FragTrap " << name << " cannot repair" << std::endl;
        return;
    }
    energy_points--;
    hit_points += amount;
    std::cout << "FragTrap " << name << " is repaired for " << amount
              << " hit points!" << std::endl;
}
