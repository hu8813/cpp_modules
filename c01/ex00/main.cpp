#include "Zombie.hpp"

int	main()
{
Zombie	zombie;
Zombie	*zombieptr;

Zombie zombie2("zombie2");
Zombie *zombie3 = zombie.newZombie("zombie3");
Zombie	zombie4 = zombie;
Zombie	zombie5 = Zombie("zombie5");
Zombie	zombie6("zombie6");
zombieptr = zombie.newZombie("zombieptr");
zombie.announce();
zombieptr->announce();
zombie2.announce();
zombie3->announce();
zombie.randomChump("ZombieRandom");
zombie4.announce();
zombie5.announce();
zombie6.announce();

delete zombieptr;
delete zombie3;

return 0;
}