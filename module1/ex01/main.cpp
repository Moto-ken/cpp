
#include "Zombie.hpp"

int main(void) {
    Zombie* zombies;
    int n = 5;
    std::string name = "ke";

    zombies = zombieHorde(n, name);

    int i = 0;
    while (i < n) {
        zombies[i].announce();
        i++;
    }

    delete[] zombies;
    return (0);
}
