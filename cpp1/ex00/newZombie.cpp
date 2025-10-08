#include "Zombie.hpp"

Zombie* newZombie( std::string name_zombie)
{
    return new Zombie(name_zombie);
}
