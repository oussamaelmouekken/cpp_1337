#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("Presidential Pardon Form", 25, 5), target(target)
{
    std::cout<<"Presidential Pardon Form constructor called \n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), target(other.target)
{
    std::cout<<"Presidential Pardon Form copy constructor called \n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
    {
        this->target = other.target;
    }
    std::cout<<"Presidential Pardon Form copy assignement constructor called \n";
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout<<"Presidential Pardon Form destructor called \n";
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!this->is_signed() || executor.getGrade() > this->getGradeRequiredToExecute()) {
        throw GradeTooLowException();
    }
    std::cout << target << " has been pardoned by Zaphod Beeblebrox.\n";
}
