#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
    brain = new Brain();
    std::cout << "Cat default constructor called" << std::endl;
}
Cat::Cat(std::string const &new_type)
{
    type = new_type;
    brain = new Brain();
	std::cout << "Cat " << this->type << " constructor called" << std::endl;
}
Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->brain = NULL;
    *this = other;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
        delete this->brain;
        if(other.brain)
        {
            this->brain = new Brain(*(other.brain));
        }
        else 
         this->brain = NULL;
    }
    return (*this);
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow\n";
}