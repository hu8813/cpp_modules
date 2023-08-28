#pragma once

#include <iostream>

class Zombie
{
	public:
		// Constructors
		Zombie();
		Zombie(const std::string &name);

		// Destructor
		~Zombie();
		
		// Getters / Setters
		std::string getName() const;

		// Functions
		void 	announce(void);
		Zombie	*newZombie(std::string name);
		void	randomChump(std::string name);
		void	setName(const std::string& name);
		Zombie* zombieHorde( int N, std::string name );

	private:
		std::string _name;
		
};
