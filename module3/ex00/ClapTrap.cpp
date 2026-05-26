
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : name("default"), hit_points(10), energy_points(10), attack_damage(0) {
    std::cout << "ClapTrap " << name << " is created" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
    : name(name), hit_points(10), energy_points(10), attack_damage(0) {
    std::cout << "ClapTrap " << name << " is created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    this->name = other.name;
    this->hit_points = other.hit_points;
    this->energy_points = other.energy_points;
    this->attack_damage = other.attack_damage;
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        this->name = other.name;
        this->hit_points = other.hit_points;
        this->energy_points = other.energy_points;
        this->attack_damage = other.attack_damage;
    }
    std::cout << "ClapTrap assignment operator called" << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " is destroyed" << std::endl;
};

void ClapTrap::attack(const std::string& target) {
    if (energy_points <= 0 || hit_points <= 0) {
        std::cout << "ClapTrap " << name << " cannot attack" << std::endl;
        return;
    }
    energy_points--;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
              << attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hit_points <= 0) return;
    if (amount >= hit_points)
        hit_points = 0;
    else
        hit_points -= amount;
    std::cout << "ClapTrap " << name << " takes " << amount << " damage!"
              << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (energy_points == 0 || hit_points == 0) {
        std::cout << "ClapTrap " << name << " cannot repair" << std::endl;
        return;
    }
    energy_points--;
    hit_points += amount;
    std::cout << "ClapTrap " << name << " is repaired for " << amount
              << " hit points!" << std::endl;
}
