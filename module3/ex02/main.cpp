
#include "FragTrap.hpp"

int main(void) {
    FragTrap ke;
    FragTrap mo("mo");
    FragTrap ha("ha");

    FragTrap* to = new FragTrap("tmp");
    while (to->getEnergyPoints() > 0) {
        to->highFivesGuys();
        if (to->getEnergyPoints() == 50) {
            ha = *to;
            // ha = ke;
        }
    }
    to->getStatus();
    delete to;

    ha.getStatus();

    std::cout << "----------------------------" << std::endl;
    ke.highFivesGuys();
    mo.attack("ke");
    ke.takeDamage(30);
    ke.getStatus();
    std::cout << "----------------------------" << std::endl;

    return 0;
}
