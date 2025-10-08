#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
class ClapTrap {

    protected:
     std::string name;
      int hitpoints;
      int energypoints;
      int attackdamage;
    public:
        ClapTrap();
        ClapTrap(const ClapTrap &another);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();

        ClapTrap(std::string newname);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
    };
#endif