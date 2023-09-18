#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
    {
        ClapTrap clapTrap1;
        ClapTrap clapTrap2("cat", 100, 100, 10);
        ScavTrap scavTrap1;
        ScavTrap scavTrap2("dog", 100, 100, 10);
        FragTrap fragTrap1;
        FragTrap fragTrap2("bird", 100, 100, 10);

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

        fragTrap1.attack("FragTrap2");
        fragTrap1.highFivesGuys();
        fragTrap2.takeDamage(10);
        fragTrap2.beRepaired(10);
        fragTrap2.attack("FragTrap1");
        fragTrap1.takeDamage(10);
        fragTrap2.highFivesGuys();
    }

    {
        DiamondTrap diamondtrap("DiamondTrap");
        std::cout << "\e[0;30mDiamondTrap Health: \e[0m HP: " << diamondtrap.getHitPoints() << ", EP: " << diamondtrap.getEnergyPoints() << ", AP: " << diamondtrap.getAttackDamage() << std::endl;

        diamondtrap.attack("DiamondTrap");

        diamondtrap.takeDamage(30);
        std::cout << "\e[0;30mDiamondTrap Health: \e[0m HP: " << diamondtrap.getHitPoints() << ", EP: " << diamondtrap.getEnergyPoints() << ", AP: " << diamondtrap.getAttackDamage() << std::endl;
        diamondtrap.beRepaired(30);
        std::cout << "\e[0;30mDiamondTrap Health: \e[0m HP: " << diamondtrap.getHitPoints() << ", EP: " << diamondtrap.getEnergyPoints() << ", AP: " << diamondtrap.getAttackDamage() << std::endl;
        diamondtrap.highFivesGuys();

        diamondtrap.whoAmI();
    }
    return (0);
}