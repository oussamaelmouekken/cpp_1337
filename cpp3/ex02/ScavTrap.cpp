#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(){
    this->hitpoints = 100;
    this->energypoints = 50;
    this->attackdamage = 20;
    std::cout << "ScavTrap Default constructor called "<< std::endl;
}

ScavTrap::ScavTrap(std::string scavname) : ClapTrap(scavname) {
    this->name =scavname;
    this->hitpoints = 100;
    this->energypoints = 50;
    this->attackdamage = 20;
    std::cout << "ScavTrap constructor called for " << this->name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) { 
    std::cout << "ScavTrap Copy constructor called for " << other.name << std::endl;
    *this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    std::cout << "ScavTrap Copy assignment operator called for " << other.name << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

// Destructor
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called"<< std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode!" << std::endl;
}

void ScavTrap :: attack(const std::string& target)
{
    if(hitpoints <= 0 || energypoints <= 0)
    {
        std::cout<<this->name <<" can't attack!\n";
        return;
    }
    std::cout<<"ScavTrap " << name << " attacks " << target<<" causing " << attackdamage<<" points of damage!\n";
    energypoints -=1;
}