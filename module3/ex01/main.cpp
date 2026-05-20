
#include "ClapTrap.hpp"

int main(void) {
    ClapTrap ke;
    ClapTrap mo(ke);
    std::string bob = "bob";
    ClapTrap to(bob);
    ClapTrap ha;
    ha = to;

    std::cout << "----------------------------" << std::endl;
    ke.attack(bob);
    to.takeDamage(0);
    mo.beRepaired(100);
    std::cout << "----------------------------" << std::endl;
    return 0;
}
