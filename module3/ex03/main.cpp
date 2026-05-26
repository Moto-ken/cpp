
#include "DiamondTrap.hpp"

int main(void) {
    DiamondTrap ke;
    DiamondTrap mo("mo");
    DiamondTrap ha("ha");

    std::cout << "----------------------------" << std::endl;
    ke.getStatus();
    mo.attack("ha");
    ha.whoAmI();
    ke.ScavTrap::beRepaired(10);
    ke.beRepaired(100);
    mo.FragTrap::highFivesGuys();
    std::cout << "----------------------------" << std::endl;

    return 0;
}
