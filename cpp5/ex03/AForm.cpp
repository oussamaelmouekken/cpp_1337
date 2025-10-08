#include "AForm.hpp"
#include "Bureaucrat.hpp"
AForm::AForm() 
    : name("Default"), signed_status(false), gradeRequiredToSign(150), gradeRequiredToExecute(150) 
{
    std::cout << "AForm default constructor\n";
}

AForm::AForm(const std::string& _name, int _gradeRequiredToSign, int _gradeRequiredToExecute)
    : name(_name), signed_status(false), gradeRequiredToSign(_gradeRequiredToSign), gradeRequiredToExecute(_gradeRequiredToExecute) 
{
    std::cout << "AForm constructor\n";
    if(_gradeRequiredToExecute < HEIGHT_GRADE || _gradeRequiredToSign < HEIGHT_GRADE)
        throw GradeTooHighException();
    else if(_gradeRequiredToExecute > LOW_GRADE || _gradeRequiredToSign > LOW_GRADE)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : name(other.name), signed_status(other.signed_status),
      gradeRequiredToSign(other.gradeRequiredToSign), gradeRequiredToExecute(other.gradeRequiredToExecute) 
{
    std::cout << "AForm copy constructor\n";
}

AForm& AForm::operator=(const AForm& other) 
{
    std::cout << "AForm copy assignment operator\n";
    if (this != &other) {
        signed_status = other.signed_status;
    }
    return *this;
}

AForm::~AForm() 
{
    std::cout << "AForm destructor\n";
}

// all getters 
const std::string& AForm::getName() const
{
    return this->name;
}

bool AForm::is_signed() const
{
    return this->signed_status;
}

int AForm::getgrade_tosign() const
{
    return this->gradeRequiredToSign;
}

int AForm::getgrade_toexecute() const
{
    return this->gradeRequiredToExecute;
}


//
int AForm::getGradeRequiredToSign() const {
    return gradeRequiredToSign;
}
int AForm::getGradeRequiredToExecute() const {
    return gradeRequiredToExecute;
}

/// function besigned
void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if(bureaucrat.getGrade() > this->gradeRequiredToSign)
    {
        throw GradeTooLowException();
    }
    else
     this->signed_status = true;
}

/// 
std::ostream &operator<<(std::ostream &os , const AForm &a)
{
    os << "AForm Name: " << a.getName() << ", Signed: ";
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

