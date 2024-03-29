#pragma once
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class Animal
{
	public:
		// Constructors
		Animal();
		Animal(std::string type);
		Animal(const Animal &copy);
		
		// Destructor
		virtual ~Animal();
		
		// Operators
		Animal & operator=(const Animal &assign);
		
		// Getters / Setters
		std::string getType() const;
		void setType(const std::string& name);
        virtual void makeSound() const;
		virtual Brain *getBrain(void);

	protected:
		std::string _type;
		
};

#endif