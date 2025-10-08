#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout<<"Cure constructor called\n";
}

Cure::Cure(const Cure& other) : AMateria(other)
{
    std::cout<<"Cure copy constructor called\n";
}

Cure& Cure::operator=(const Cure& other)
{
    if (this != &other)
    {
        AMateria::operator=(other);
    }
    std::cout<<"Cure copy assignement constructor called\n";
    return *this;
}

Cure::~Cure()
{
    std::cout<<"Cure destructor called\n";
}

AMateria *Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}