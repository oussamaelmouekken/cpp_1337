#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() 
    : name("Default"), signed_status(false), gradeRequiredToSign(150), gradeRequiredToExecute(150) 
{
    std::cout << "Form default constructor\n";
}

Form::Form(const std::string& _name, int _gradeRequiredToSign, int _gradeRequiredToExecute)
    : name(_name), signed_status(false), gradeRequiredToSign(_gradeRequiredToSign), gradeRequiredToExecute(_gradeRequiredToExecute) 
{
    std::cout << "Form constructor\n";
    if(_gradeRequiredToExecute < HEIGHT_GRADE || _gradeRequiredToSign < HEIGHT_GRADE)
        throw GradeTooHighException();
    else if(_gradeRequiredToExecute > LOW_GRADE || _gradeRequiredToSign > LOW_GRADE)
        throw GradeTooLowException();
}

Form::Form(const Form& other)
    : name(other.name), signed_status(other.signed_status),
      gradeRequiredToSign(other.gradeRequiredToSign), gradeRequiredToExecute(other.gradeRequiredToExecute) 
{
    std::cout << "Form copy constructor\n";
}

Form& Form::operator=(const Form& other) 
{
    std::cout << "Form copy assignment operator\n";
    if (this != &other) {
        signed_status = other.signed_status;
    }
    return *this;
}

Form::~Form() 
{
    std::cout << "Form destructor\n";
}

// all getters 
const std::string& Form::getName() const
{
    return this->name;
}

bool Form::is_signed() const
{
    return this->signed_status;
}

int Form::getgrade_tosign() const
{
    return this->gradeRequiredToSign;
}

int Form::getgrade_toexecute() const
{
    return this->gradeRequiredToExecute;
}
/// function besigned
void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if(bureaucrat.getGrade() > this->gradeRequiredToSign || this->signed_status)
    {
        throw GradeTooLowException();
    }
    else
     this->signed_status = true;
}

/// 
std::ostream &operator<<(std::ostream &os , const Form &a)
{
    os << "Form Name: " << a.getName() << ", Signed: ";
    if (a.is_signed())
    {
        os << "Yes";
    }
    else
    {
        os << "No";
    }
    os << ", Grade to Sign: " << a.getgrade_tosign()
       << ", Grade to Execute: " << a.getgrade_toexecute();
    return os;
}
