
#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
    // この関数はゾンビを作成し、名前を付けて返します。これにより、関数スコープ外でもゾンビを使用できます。
    Zombie* z;

    z = new Zombie;
    z->setName(name);
    return (z);
}
