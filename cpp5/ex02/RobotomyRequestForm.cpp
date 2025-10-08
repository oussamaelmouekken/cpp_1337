#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request Form", 72, 45), target(target)
{
    std::cout<<"Robotomy Request Form constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target)
{
    std::cout<<"Robotomy Request Form copy constructor called\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        this->target = other.target;
    }
    std::cout<<"Robotomy Request Form copy assignement constructor called\n";
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout<<"Robotomy Request Form destructor called\n";
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!this->is_signed() || (executor.getGrade() > this->getGradeRequiredToExecute())) {
        throw GradeTooLowException();
    }
    std::cout << "---------drilling noises\n";
    srand(time(0));
    if (rand() % 2)
        std::cout << target << " robotomized successfully\n";
    else
        std::cout << target << " robotomization failed\n";
}
