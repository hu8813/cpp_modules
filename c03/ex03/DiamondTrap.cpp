#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("NoName_clap_name"), ScavTrap("NoName_clap_name"), FragTrap("NoName_clap_name"), _name("NoName")
{
    FragTrap::_hitPoints = 100;
    ScavTrap::_energyPoints = 50;
    FragTrap::_attackDamage = 30;
    std::cout << "DiamondTrap Default Constructor called"
              << " HP: " << _hitPoints << ", EP: " << _energyPoints << ", AP: " << _attackDamage << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
    FragTrap::_hitPoints = 100;
    ScavTrap::_energyPoints = 50;
    FragTrap::_attackDamage = 30;
    std::cout << "DiamondTrap Name Constructor called"
              << " HP: " << DiamondTrap::_hitPoints << ", EP: " << _energyPoints << ", AP: " << _attackDamage << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &assign)
{
    this->_name = assign.getName();
    this->_energyPoints = assign.getEnergyPoints();
    this->_hitPoints = assign.getHitPoints();
    this->_attackDamage = assign.getAttackDamage();
    return *this;
    std::cout << "DiamondTrap Copy assignment called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy) : ClapTrap(), ScavTrap(), FragTrap()
{
    *this = copy;
    std::cout << "DiamondTrap Constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Deconstructor called" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "DiamondTrap Name: " << _name << ", ClapTrap Name: " << ClapTrap::_name << std::endl;
}

// void DiamondTrap::attack(std::string const &target)
// {
//     ScavTrap::attack(target);
// }
