#include "Zombie.hpp"

void Zombie::set_name(std::string new_name)
{
    name = new_name;
}
void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}