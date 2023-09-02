#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat: public AAnimal
{
	public:
		// Constructors
		Cat();
		Cat(std::string type);
		Cat(const Cat &copy);
		
		// Destructor
		~Cat();
		
		// Operators
		Cat & operator=(const Cat &assign);
		
		// Methods
		void makeSound() const;
        std::string getType() const;
	private:
		Brain *brain;
};

#endif