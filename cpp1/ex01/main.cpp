#include "Zombie.hpp"

int main()
{
    int input = 5;
    Zombie*z = zombieHorde(input, "zombie--^^--");
    for(int i = 0;i < input; i++)
    {
        z[i].announce();
    }
    delete[]z;
    return 0;
}

