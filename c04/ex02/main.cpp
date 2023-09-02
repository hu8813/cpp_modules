#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
//const AAnimal* meta = new AAnimal();
const AAnimal* j = new Dog();
const AAnimal* i = new Cat();

std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
//meta->makeSound();

const AAnimal* malteser = new Dog();
const AAnimal* vanCat = new Cat();
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

return 0;

}