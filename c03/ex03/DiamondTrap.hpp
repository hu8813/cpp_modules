#pragma once

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(DiamondTrap const &copy);
    ~DiamondTrap();

    DiamondTrap &operator=(DiamondTrap const &assign);

    void whoAmI(void);
    // void attack(const std::string &target);
    using ScavTrap::attack;

private:
    std::string _name;
};
