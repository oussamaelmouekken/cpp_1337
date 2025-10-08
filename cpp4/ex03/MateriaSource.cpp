#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _learnedCount(0)
{
    for (int i = 0; i < MAX_LEARNED_MATERIAS; i++)
    {
        this->_learnedMaterias[i] = NULL;
    }
    std::cout<<"MateriaSource constructor called \n";
}

MateriaSource::MateriaSource(MateriaSource const & src) : _learnedCount(0)
{
    for (int i = 0; i < MAX_LEARNED_MATERIAS; i++)
    {
        this->_learnedMaterias[i] = NULL; 
    }
    this->_copyLearnedMaterias(src);
    std::cout<<"MateriaSource copy constructor called\n";
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs)
{
    if (this != &rhs)
    {
        this->_clearLearnedMaterias();
        this->_copyLearnedMaterias(rhs);
    }
    std::cout<<"MateriaSource copy assignement constructor called\n";
    return *this;
}

MateriaSource::~MateriaSource()
{
    this->_clearLearnedMaterias();
    std::cout<<"MateriaSource destructor called\n";
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m || this->_learnedCount >= MAX_LEARNED_MATERIAS)
    {   
        return;
    }
    this->_learnedMaterias[this->_learnedCount] = m->clone();
    this->_learnedCount++;
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < this->_learnedCount; i++)
    {
        if (this->_learnedMaterias[i] && this->_learnedMaterias[i]->getType() == type)
        {
            return this->_learnedMaterias[i]->clone();
        }
    }
    return NULL;
}

void MateriaSource::_clearLearnedMaterias()
{
    for (int i = 0; i < this->_learnedCount; i++) 
    {
        delete this->_learnedMaterias[i];
        this->_learnedMaterias[i] = NULL;
    }
    this->_learnedCount = 0;
}

void MateriaSource::_copyLearnedMaterias(const MateriaSource& src)
{
    this->_learnedCount = 0; 
    for (int i = 0; i < src._learnedCount; i++)
    {
        if (src._learnedMaterias[i] != NULL)
        {
            this->_learnedMaterias[i] = src._learnedMaterias[i]->clone();
            this->_learnedCount++;
        }
        else
        {
            this->_learnedMaterias[i] = NULL;
        }
    }
    // Ensure remaining slots are NULL if src had fewer learned materias
    for (int i = this->_learnedCount; i < MAX_LEARNED_MATERIAS; i++) {
        this->_learnedMaterias[i] = NULL;
    }
}
