
#ifndef WEONGANIMAL_HPP
#define WEONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
   protected:
    std::string type;

   public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal(const std::string& name);
    WrongAnimal& operator=(const WrongAnimal& other);
    ~WrongAnimal();

    void makeSound() const;
    std::string getType() const;
};

#endif
