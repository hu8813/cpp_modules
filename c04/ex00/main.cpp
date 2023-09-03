#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
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

return 0;

}