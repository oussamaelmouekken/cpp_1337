#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("oussama", 150);
        std::cout<< b1.getGrade()<< std::endl;
        std::cout<< b1.getName()<< std::endl;
        std :: cout << b1 << std::endl;
        b1.decrementGrade();
    }
    catch(const std::exception &e)
    {
        std::cerr << "An unexpected exception occurred: " << e.what() << std::endl;
    }
    return 0;
}
