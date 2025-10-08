#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <iostream>

class Zombie
{
    private:
        std::string name;
    public:
        Zombie(std::string new_name);
        ~Zombie();
        void announce(void);
};

Zombie* newZombie( std::string name_zombie);
void randomChump(std::string name);

#endif