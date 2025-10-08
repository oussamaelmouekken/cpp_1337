#ifndef WRONGCAT_ANIMAL_HPP
# define WRONGCAT_ANIMAL_HPP

# include <string>
# include <iostream>

class WrongAnimal
{
    protected:
        std::string type;

    public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &other);
    WrongAnimal(std::string const &new_type);
    WrongAnimal &operator=(const WrongAnimal &other);
    ~WrongAnimal();

    std::string getType() const;

    void makeSound() const;
};

class WrongCat : public WrongAnimal
{
    public:
    WrongCat();
    WrongCat(const WrongCat &other);
    WrongCat(std::string const &new_type);
    WrongCat &operator=(const WrongCat &other);
    ~WrongCat();

    void makeSound() const;
};

#endif