
#include "Zombie.hpp"

void randomChump(std::string name) {
    // この関数はゾンビを作成し、名前を付け、自己紹介させます。
    Zombie zombie;

    zombie.setName(name);
    zombie.announce();
}
