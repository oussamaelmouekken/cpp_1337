#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <iostream>

# define Inventory_size 4

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria*	_inventory[Inventory_size];

    public:
        Character();
        Character(std::string const & name);
        Character(Character const & src);
        Character & operator=(Character const & rhs);
        virtual ~Character();

        virtual std::string const & getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
};

#endif