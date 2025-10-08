#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp" 
#include <string>
#include <iostream>

class FragTrap : virtual public ClapTrap { 
private:
public:
    FragTrap();
    FragTrap(std::string fragname);
    FragTrap(const FragTrap& other);
    FragTrap& operator=(const FragTrap& other);
    ~FragTrap();
    void highFivesGuys(void);
};

#endif 