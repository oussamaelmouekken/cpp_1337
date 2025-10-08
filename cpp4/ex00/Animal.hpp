#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{
    protected:
        std::string type;

    public:
        Animal();
        Animal(const Animal &other);
        Animal(std::string const &new_type);
        Animal &operator=(const Animal &other);
        virtual ~Animal();

        std::string getType() const;

        virtual void makeSound() const;
};

#endif