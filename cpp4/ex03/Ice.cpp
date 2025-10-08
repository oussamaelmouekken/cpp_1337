#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout<<"Ice constructor called\n";
}

Ice::Ice(const Ice& other) : AMateria(other)
{
    std::cout<<"Ice copy constructor called\n";
}

Ice& Ice::operator=(const Ice& other)
{
    if (this != &other)
    {
        AMateria::operator=(other);
    }
    std::cout<<"Ice copy assignement constructor called\n";
    return *this;
}

Ice::~Ice()
{
    std::cout<<"Ice destructor called\n";
}
AMateria *Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
    std::cout<<"* shoots an ice bolt at "<<target.getName()<< " *"<<std::endl;
}
