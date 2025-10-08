#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    this->hitpoints = 100;
    this->energypoints = 100;
    this->attackdamage = 30;
    std::cout << "FragTrap Default constructor called " << std::endl;
}

FragTrap::FragTrap(std::string fragname) : ClapTrap(fragname) {
    this->name = fragname;
    this->hitpoints = 100;
    this->energypoints = 100;
    this->attackdamage = 30;
    std::cout << "FragTrap name constructor called for " << this->name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    std::cout << "FragTrap Copy constructor called for " << other.name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    std::cout << "FragTrap copy assignment operator called for " << other.name << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap Destructor called"<< std::endl;
}


void FragTrap::highFivesGuys(void) {
    if (this->hitpoints <= 0) {
        std::cout << "FragTrap " << this->name << " can't request high fives, it's destroyed!" << std::endl;
        return;
    }
     if (this->energypoints <= 0) {
        std::cout << "FragTrap " << this->name << " has no energy left for high fives!" << std::endl;
        return;
    }
    std::cout << "FragTrap " << this->name << " : Give me a high five!\n";
}