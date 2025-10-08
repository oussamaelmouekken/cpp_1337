#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() 
{
    try
    {
        Bureaucrat b("B", 4);
        RobotomyRequestForm P("ddd");
        P.beSigned(b);
        P.execute(b);
        b.executeForm(P);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
