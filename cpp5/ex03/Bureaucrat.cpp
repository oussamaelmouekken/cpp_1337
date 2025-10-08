#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150) 
{
    std::cout << "Bureaucrat default constructor\n";
}

Bureaucrat::Bureaucrat(const std::string& _name, int _grade):name(_name)
{
    std::cout<<"Bureaucrat constructor\n";
    if(_grade < 1)
    {
        throw GradeTooHighException();
    }
    else if(_grade > 150)
    {
        throw GradeTooLowException();
    }
    grade = _grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{
    std::cout<<"Bureaucrat copy constructor \n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "Bureaucrat copy assignment operator\n";
    if (this != &other) {
        grade = other.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor\n";
}

int Bureaucrat :: getGrade() const
{
    return (this->grade);
}
std::string Bureaucrat :: getName() const
{
    return (this->name);
}
void Bureaucrat::incrementGrade()
{
    if(grade - 1 < 1)
        throw GradeTooHighException();
    grade--;
}
void Bureaucrat::decrementGrade()
{
    if(grade + 1 > 150)
        throw GradeTooLowException();
    grade++;
}
std::ostream &operator<<(std::ostream &os , const Bureaucrat &a)
{
    os << a.getName() << ", bureaucrat grade " << a.getGrade() << ".";
    return os ;
}

void Bureaucrat::signAForm(AForm& AForm) {
    try 
    {
        AForm.beSigned(*this);
        std::cout << this->name << " signed " << AForm.getName() << std::endl;
    } 
    catch (const AForm::GradeTooLowException& e) 
    {
        std::cout << this->name << " couldn't sign " << AForm.getName() 
                  << " because their grade is too low." << std::endl;
    }
}
