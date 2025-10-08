#include "AMateria.hpp"

AMateria::AMateria()
{
    std::cout<<"AMateria default constructor called\n";
}

AMateria::AMateria(std::string const & type) : type(type)
{
    std::cout<<"AMateria constructor called\n";
}

AMateria::AMateria(const AMateria& other) : type(other.type)
{
    std::cout<<"AMateria copy constructor called\n";
}

AMateria& AMateria::operator=(const AMateria& other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    std::cout<<"AMateria copy assignement constructor called\n"; 
    return *this;
}

AMateria::~AMateria()
{
    std::cout<<"AMateria destructor called\n";
}

std::string const & AMateria::getType() const
{
    return this->type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}