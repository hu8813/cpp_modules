#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap clapTrap1;
    ClapTrap clapTrap2("cat", 100, 100, 10);
    ClapTrap clapTrap3(clapTrap2);
    ClapTrap clapTrap4;
    clapTrap4 = clapTrap3;

    clapTrap1.attack("ClapTrap2");
    clapTrap2.takeDamage(10);
    clapTrap2.beRepaired(10);
    clapTrap2.attack("ClapTrap1");
    clapTrap1.takeDamage(10);
    clapTrap1.beRepaired(10);
    clapTrap1.attack("ClapTrap3");
    clapTrap3.takeDamage(10);
    clapTrap3.beRepaired(10);
    clapTrap3.attack("ClapTrap4");
    clapTrap4.takeDamage(10);
    clapTrap4.beRepaired(10);
    clapTrap4.attack("ClapTrap1");

    return (0);
}