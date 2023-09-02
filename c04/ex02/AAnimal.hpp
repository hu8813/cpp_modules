#ifndef AAnimal_HPP
# define AAnimal_HPP

# include <iostream>

class AAnimal
{
	public:
		// Constructors
		AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal &copy);
		
		// Destructor
		virtual ~AAnimal();
		
		// Operators
		AAnimal & operator=(const AAnimal &assign);
		
		// Getters / Setters
		virtual std::string getType() const;
		void setType(const std::string& name);
        virtual void makeSound() const = 0;
		
	protected:
		std::string _type;
		
};

#endif