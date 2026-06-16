
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    std::cout << "===== Animal array test =====\n";
    Animal* animals[10];

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

    std::cout << "\n===== Deep copy test (Cat / Brain) =====\n";
    Cat cat1;

    cat1.getBrain()->setIdea(0, "A");
    Cat cat2 = cat1;
    std::cout << "Before change:\n";
    std::cout << "cat1: " << cat1.getBrain()->getIdea(0) << "\n";
    std::cout << "cat2: " << cat2.getBrain()->getIdea(0) << "\n";

    cat2.getBrain()->setIdea(0, "B");
    std::cout << "\nAfter change:\n";
    std::cout << "cat1: " << cat1.getBrain()->getIdea(0) << "\n";
    std::cout << "cat2: " << cat2.getBrain()->getIdea(0) << "\n";

    return 0;
}
