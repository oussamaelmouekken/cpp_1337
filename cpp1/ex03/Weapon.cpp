#include"Weapon.hpp"

const std::string Weapon::getType()
{
    const std::string &ref = type;
    return ref;
}
void Weapon ::setType(std::string new_type)
{
    type = new_type;
}
Weapon::Weapon(std::string name)
{
    type = name;
}