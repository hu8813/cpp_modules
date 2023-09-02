#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	public:
		// Constructors
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &copy);
		
		// Destructor
		virtual ~WrongAnimal();
		
		// Operators
		WrongAnimal & operator=(const WrongAnimal &assign);
		
		// Getters / Setters
		virtual std::string getType() const;
		virtual void makeSound() const = 0;
		void setType(const std::string& name);
		
	protected:
		std::string _type;
		
};

#endif