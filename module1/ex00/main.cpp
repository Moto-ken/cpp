
#include "Zombie.hpp"

int main() {
    Zombie* z = newZombie("ke");
    z->announce();

    randomChump("mo");
    delete z;

    Zombie zombie;
    return (0);
}
