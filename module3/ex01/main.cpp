
#include "ScavTrap.hpp"

int main(void) {
    ClapTrap* ke = new ScavTrap("ke");
    std::string enemy = "mo";
    ScavTrap mo(enemy);

    std::cout << "----------------------------" << std::endl;
    ke->attack(enemy);
    mo.takeDamage(10);
    mo.beRepaired(11);
    dynamic_cast<ScavTrap*>(ke)->guardGate();

    while (mo.getHitPoints() > 0) {
        ke->attack(enemy);
        mo.takeDamage(20);
    }
    mo.getStatus();
    std::cout << "----------------------------" << std::endl;
    delete ke;
    return 0;
}
