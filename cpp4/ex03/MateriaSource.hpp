#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

# define MAX_LEARNED_MATERIAS 4

class MateriaSource : public IMateriaSource
{
    private:
        AMateria*	_learnedMaterias[MAX_LEARNED_MATERIAS];
        int			_learnedCount;

        void _clearLearnedMaterias();
        void _copyLearnedMaterias(const MateriaSource& src);

    public:
        MateriaSource();
        MateriaSource(MateriaSource const & src);
        MateriaSource & operator=(MateriaSource const & rhs);
        virtual ~MateriaSource();

        virtual void learnMateria(AMateria* m);
        virtual AMateria* createMateria(std::string const & type);
};

#endif