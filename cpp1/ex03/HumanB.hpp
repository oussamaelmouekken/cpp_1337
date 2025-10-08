#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"
# include "iostream"

class HumanB
{
  private:
	std::string name;
	Weapon *weapon;

  public:
  HumanB(std::string name_) : name(name_),
  weapon(NULL)
		{}
	void setWeapon(Weapon &new_weapon);
	void attack();
};
#endif