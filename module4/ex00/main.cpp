
#include "Animal.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "dog.hpp"

int main(void) {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout << "----------------------------" << std::endl;
    WrongAnimal* a = new WrongCat();
    a->makeSound();
    delete a;
    std::cout << "----------------------------" << std::endl;
    delete meta;
    delete j;
    delete i;

    return (0);
}
