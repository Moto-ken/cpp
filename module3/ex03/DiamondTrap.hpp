
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
   private:
    std::string _name;

   public:
    DiamondTrap();
    DiamondTrap(const std::string diamondName);
    DiamondTrap(const DiamondTrap& ohter);
    DiamondTrap& operator=(const DiamondTrap& other);
    ~DiamondTrap();

    void whoAmI();
    // over ride
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);

    void beRepaired(unsigned int amount);
    // void guardGate();
    // void highFivesGuys(void);
};

#endif
