#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() 
{
    Intern someIntern;
    AForm* rrf;
    Bureaucrat bureaucrat("John", 20);

    rrf = someIntern.makeForm("robotomy request", "Bender");
    if(rrf != NULL)
     std::cout <<"exist\n";
    else 
     std::cout<<"not exist\n";
    bureaucrat.signAForm(*rrf);
    bureaucrat.executeForm(*rrf);
    delete rrf;
    return 0;
}
