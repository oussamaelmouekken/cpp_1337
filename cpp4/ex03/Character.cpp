#include "Character.hpp"
#include <iostream>

Character::Character()
{
	for (int i = 0; i < Inventory_size; i++)
	{
		this->_inventory[i] = NULL;
	}
	std::cout<<"Character default constructor called\n";
}

Character::Character(std::string const &name) : _name(name)
{
	for (int i = 0; i < Inventory_size; i++)
	{
		this->_inventory[i] = NULL;
	}
	std::cout<<"Character constructor called\n";
}

// copy constructor 
Character::Character(Character const &other) : _name(other._name)
{
	for (int i = 0; i < Inventory_size; i++)
	{
		this->_inventory[i] = NULL;
	}
	for (int i = 0; i < Inventory_size; i++)
	{
		if (other._inventory[i] != NULL)
		{
			this->_inventory[i] = other._inventory[i]->clone();
		}
		else
		{
			this->_inventory[i] = NULL;
		}
	}
	std::cout<<"Character copy constructor called\n";
}

// copy assignement constructor 
Character &Character::operator=(Character const &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		// clear
		for (int i = 0; i < Inventory_size; i++)
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
		// copy other
		for (int i = 0; i < Inventory_size; i++)
		{
			if (other._inventory[i] != NULL)
			{
				this->_inventory[i] = other._inventory[i]->clone();
			}
			else
			{
				this->_inventory[i] = NULL;
			}
		}
	}
	std::cout<<"Character copy assignement constructor called\n";
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < Inventory_size; i++)
	{
		delete this->_inventory[i];
		this->_inventory[i] = NULL;
	}
	std::cout<<"Character destructor called\n";
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria *m)
{
	if (!m)
		return ;
	for (int i = 0; i < Inventory_size; i++)
	{
        /// check first empty
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < Inventory_size)
	{
		this->_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < Inventory_size && this->_inventory[idx] != NULL)
	{
		this->_inventory[idx]->use(target);
	}
}
