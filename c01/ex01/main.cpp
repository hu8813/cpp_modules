#include "Zombie.hpp"

int main()
{
    Zombie zombie;

    Zombie* zombies = zombie.zombieHorde(5, "Zombie");

    delete[] zombies;

    return 0;
}
