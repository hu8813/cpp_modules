#pragma once
#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
	public:
		// Constructors
		Dog();
		Dog(std::string type);
		Dog(const Dog &copy);
		
		// Destructor
		~Dog();
		
		// Operators
		Dog & operator=(const Dog &assign);
		
		// Methods
		void makeSound() const;
        std::string getType() const;
		Brain *getBrain(void);
	private:
		Brain *_brain;
};

#endif