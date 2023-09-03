#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#define MAX_ANIMALS 4

int main() {
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); 
        j->makeSound();
        meta->makeSound();

        const Animal* malteser = new Dog();
        const Animal* vanCat = new Cat();
        malteser->makeSound();
        vanCat->makeSound();

        const WrongAnimal* aWrongCat = new WrongCat();
        aWrongCat->makeSound();

        delete meta;
        delete j;
        delete i;
        delete malteser;
        delete vanCat;
        delete aWrongCat;
    }

    {
    Animal *animals[MAX_ANIMALS];
    Brain *brain;

    for (int i=0; i < MAX_ANIMALS/2; i++)
    {
        animals[i] = new Dog();
    }
    for (int i=MAX_ANIMALS/2; i < MAX_ANIMALS; i++)
    {
        animals[i] = new Cat();
    }

    for (int i=0; i < MAX_ANIMALS; i++)
    {
        brain = animals[i]->getBrain();
            for (int k=0; k<1; k++)
            {
                if (brain->getIdeas()[k][0])
                std::cout << animals[i]->getType() << " has Idea #" << k << " "<<  brain->getIdeas()[k] << std::endl;
            }
    }


    for (int i=0; i < MAX_ANIMALS; i++)
    {
        delete animals[i];
    }

    }
    return 0;
}
