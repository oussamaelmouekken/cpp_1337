#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>
#include <string>

class Zombie
{
private:
    std::string name;
public:
    void set_name(std::string new_name);
    void announce(void);
};

Zombie* zombieHorde(int N, std::string new_name);

#endif