#include "Zombie.hpp"

void Zombie::randomChump(std::string name) {
	Zombie zombierandom(name);
	zombierandom.announce();
}