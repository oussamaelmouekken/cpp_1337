#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
    this->hitpoints = FragTrap::hitpoints;
    this->energypoints = ScavTrap::energypoints;
    this->attackdamage = FragTrap::attackdamage;
    std::cout << "DiamondTrap Default constructor called "<< std::endl;
}

DiamondTrap::DiamondTrap(std::string diamondname) : 
    ClapTrap(diamondname + "_clapname"),
    name(diamondname)
    {
    this->hitpoints = FragTrap::hitpoints;
    this->energypoints = ScavTrap::energypoints;
    this->attackdamage = FragTrap::attackdamage;
    std::cout << "DiamondTrap Name constructor called for " << this->name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
    this->name = other.name;
    std::cout << "DiamondTrap Copy constructor called for " << this->name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    std::cout << "DiamondTrap Copy assignment operator called for " << other.name << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
        this->name = other.name;
        this->hitpoints = other.hitpoints;
        this->energypoints = other.energypoints;
        this->attackdamage = other.attackdamage;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap Destructor called "<< std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << "My DiamondTrap name is: " << this->name << std::endl;
    std::cout << "My ClapTrap name is: " << ClapTrap::name << std::endl;
}
