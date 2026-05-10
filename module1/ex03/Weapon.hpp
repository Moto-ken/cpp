
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
   private:
    std::string weapon;

   public:
    Weapon(std::string type);
    ~Weapon();
    void setType(std::string type);
    std::string getType(void) const;
};

#endif
