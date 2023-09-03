#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#define MAX_ANIMALS 4

int main()
{
{
    //const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); 
    j->makeSound();
    //meta->makeSound();

    const Animal* malteser = new Dog();
    const Animal* vanCat = new Cat();
    malteser->makeSound();
    vanCat->makeSound();

    const WrongAnimal* aWrongCat = new WrongCat();
    aWrongCat->makeSound();

    //delete meta;
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
    {
        Dog bulldog;
        Cat mimi;

        Dog &bulldogRef = bulldog;
        Cat &mimiRef = mimi;

        Dog bulldogCopy(bulldogRef);
        Cat mimiCopy(mimiRef);

        std::cout  << std::endl << "comparing Address:" << std::endl;

        std::cout << "heap Address of bulldog's brain: "<< bulldog.getBrain() << std::endl;         
        std::cout << "heap Address of bulldogCopy's brain: "<< bulldogCopy.getBrain() << std::endl;         

        std::cout << "heap Address of mimi's brain: "<< mimi.getBrain() << std::endl;         
        std::cout << "heap Address of mimiCopy's brain: "<< mimiCopy.getBrain() << std::endl;         
        
        bool sameValues = 1;
        std::cout  << std::endl << "Comparing values:" << std::endl;
        for (int i = 0; i < 100; i++)
            if ((bulldog.getBrain())->getIdeas()[i] != (bulldogCopy.getBrain())->getIdeas()[i])
                {
                    std::cout << (bulldog.getBrain())->getIdeas()[i] << std::endl;
                    std::cout << (bulldogCopy.getBrain())->getIdeas()[i] << std::endl;
                    sameValues = 0;
                    break;
                }
        
        if (!sameValues)
            std::cout << "Error in Copy, the values are not identic" << std::endl;
        else
            std::cout << "Both values are same!" << std::endl;

    }
    return 0;
}