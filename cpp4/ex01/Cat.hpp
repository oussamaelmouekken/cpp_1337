#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
     Brain *brain;
    public:
        Cat();
        Cat(const Cat &other);
        Cat(std::string const &new_type);
        Cat &operator=(const Cat &other);
        ~Cat();

        void makeSound() const;
};

#endif