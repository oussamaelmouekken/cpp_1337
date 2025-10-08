#include "ClapTrap.hpp"
int main()
{
    ClapTrap hero("hero");
    ClapTrap vil("vil");
    hero.attack("vil");
    hero.takeDamage(3);
    hero.takeDamage(3);
    hero.takeDamage(2);
    hero.attack("vil");
    //vil.takeDamage(10);
    //vil.attack("hero");
    return 0;
}

