#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("NoName_clap_name"), ScavTrap(), FragTrap(), _name("NoName")
{
    _energyPoints = ScavTrap::getEnergyPoints();
    std::cout << "DiamondTrap Constructor called" << std::endl;

}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name+"_clap_name"), ScavTrap(), FragTrap(), _name(name)
{
    //_energyPoints = ScavTrap::getEnergyPoints();
    _energyPoints = ScavTrap::_attackDamage;
    std::cout << "DiamondTrap Constructor called" << std::endl;

}


DiamondTrap& DiamondTrap::operator=(DiamondTrap const &assign)
{
    this->_name = assign.getName();
	this->_energyPoints = assign.getEnergyPoints();
	this->_hitPoints = assign.getHitPoints();
	this->_attackDamage = assign.getAttackDamage();
    return *this;
    std::cout << "DiamondTrap Copy assignment called" << std::endl;

}

DiamondTrap::DiamondTrap(DiamondTrap const & copy): ClapTrap(), ScavTrap(), FragTrap()  
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
    std::cout << "DiamondTrap Name: " << _name << ", ClapTrap Name: " << _name << std::endl;
}

// void DiamondTrap::attack(std::string const &target)
// {
//     ScavTrap::attack(target);
// }

