#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap clapTrap1;
    ClapTrap clapTrap2("cat", 100, 100, 10);
    ScavTrap scavTrap1;
    ScavTrap scavTrap2("dog", 100, 100, 10);

    clapTrap1.attack("ClapTrap2");
    clapTrap2.takeDamage(10);
    clapTrap2.beRepaired(10);
    clapTrap2.attack("ClapTrap1");
    clapTrap1.takeDamage(10);
    clapTrap1.beRepaired(10);

    scavTrap1.attack("ScavTrap2");
    scavTrap1.guardGate();
    scavTrap2.takeDamage(10);
    scavTrap2.beRepaired(10);
    scavTrap2.attack("ScavTrap1");
    scavTrap1.takeDamage(10);
    scavTrap2.guardGate();

    return (0);
}