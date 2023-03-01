#include "Zombie.hpp"

int	main()
{
	Zombie	zombie;
	Zombie	*zombieptr;
    Zombie zom2("zom");
    Zombie *zom = zombie.newZombie("zom2");

	zombieptr = zombie.newZombie("42zombie");
	zombie.announce();
	zombieptr->announce();
    zom2.announce();
    zom->announce();
	zombie.randomChump("Zombie");
	delete zombieptr;
    delete zom;
    return 0;
}