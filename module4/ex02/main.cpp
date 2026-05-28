
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    std::cout << "===== Animal array test =====\n";
    AAnimal* animals[10];

    for (int i = 0; i < 10; i++) {
        if (i < 5)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    std::cout << "----- Sounds -----\n";
    for (int i = 0; i < 10; i++) {
        animals[i]->makeSound();
    }
    std::cout << "----- Deleting -----\n";
    for (int i = 0; i < 10; i++) {
        delete animals[i];
    }

    // // NG implementation
    // AAnimal* meta = new AAnimal();
    // meta->makeSound();
    // delete meta;

    return 0;
}
