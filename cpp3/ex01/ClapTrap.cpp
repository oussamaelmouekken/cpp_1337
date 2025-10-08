#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
     hitpoints = 10;
     energypoints = 10;
     attackdamage =0;
     std::cout<<"ClapTrap default constructor called\n";  
}
// coustructor with name
ClapTrap::ClapTrap(std::string newname)
{
    this->name = newname;
    hitpoints = 10;
    energypoints = 10;
    attackdamage =0;
    std::cout <<"ClapTrap " << this->name << " constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout<<"ClapTrap Destructor called\n";
}

ClapTrap :: ClapTrap(const ClapTrap &another)
{
    std::cout<<"ClapTrap Copy constructor called\n";
    *this = another;
}

ClapTrap &ClapTrap ::operator=(const ClapTrap &another)
{
    std::cout<<"ClapTrap Copy assignment operator called\n";
    if(this != &another)
    {
        this->name = another.name;
        this->hitpoints = another.hitpoints;
        this->energypoints = another.energypoints;
        this->attackdamage = another.attackdamage;
    }
    return *this ; 
}

void ClapTrap :: attack(const std::string& target)
{
    if(hitpoints <= 0 || energypoints <= 0)
    {
        std::cout<<this->name <<" can't attack!";
        return;
    }
    std::cout<<"ClapTrap " << name << " attacks " << target<<" causing " << attackdamage<<" points of damage!\n";
    energypoints -=1;
}

void ClapTrap :: takeDamage(unsigned int amount)
{
    if(hitpoints <= 0)
    {
        std::cout << this->name <<"has been destroyed!\n";
        return;
    }
    hitpoints = hitpoints - amount;
    std::cout<<"ClapTrap "<< this->name<<" takes "<< amount << " damage, losing " <<amount <<" hit points!\n";
    if(hitpoints <= 0)
      std::cout << this->name <<" has been destroyed!\n";
}

void ClapTrap :: beRepaired(unsigned int amount)
{
    if(hitpoints <= 0 || energypoints <= 0)
    {
        std::cout<<this->name <<" can't repair itself!";
        return;
    }
    hitpoints = hitpoints + amount;
    if(hitpoints >10)
    {
        std::cout<<this->name <<" is at full health now!\n";
        return;
    }
    energypoints -=1;
    std::cout<<"ClapTrap" << this->name<<" repairs itself, regaining "<< amount<<" hit points!\n";
}
