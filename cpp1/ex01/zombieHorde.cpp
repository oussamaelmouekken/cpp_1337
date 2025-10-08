#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string new_name)
{
    Zombie *hord_zombie = new Zombie[N];
    for(int i = 0;i < N; i++)
    {
        hord_zombie[i].set_name(new_name);
    }
    return hord_zombie;
}