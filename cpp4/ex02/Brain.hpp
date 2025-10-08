#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain
{
    private:
        std::string ideas[100];

    public:
        Brain();
        Brain(const Brain &other);
        Brain(std::string  &new_name);
        Brain &operator=(const Brain &other);
        ~Brain();
};

#endif