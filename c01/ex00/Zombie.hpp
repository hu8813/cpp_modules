#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	public:
		// Constructors
		Zombie();
		Zombie(const Zombie &copy);
		Zombie(const std::string &name);

		// Destructor
		~Zombie();
		
		// Operators
		Zombie & operator=(const Zombie &assign);
		
		// Getters / Setters
		std::string getName() const;

		// Functions
		void announce(void);
		Zombie	*newZombie(std::string name);
		void	randomChump(std::string name);
		
	private:
		std::string _name;
		
};

#endif