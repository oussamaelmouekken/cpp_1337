#include "Zombie.hpp"

int main()
{
    Zombie*z = newZombie("ooo");
    z->announce();
    randomChump("oussama");
    delete z; 
    return 0;
}
