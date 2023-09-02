#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog: public AAnimal
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
	private:
		Brain *brain;
};

#endif