#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"
# include "Brain.hpp"

class WrongCat: public WrongAnimal
{
	public:
		// Constructors
		WrongCat();
		WrongCat(std::string type);
		WrongCat(const WrongCat &copy);
		
		// Destructor
		~WrongCat();
		
		// Operators
		WrongCat & operator=(const WrongCat &assign);
		
		// Methods
		void makeSound() const;
        std::string getType() const;
	private:
		Brain *brain;
};

#endif