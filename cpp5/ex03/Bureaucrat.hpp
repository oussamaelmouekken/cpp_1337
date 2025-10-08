#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <ostream>
#include "AForm.hpp"

class AForm;
class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
     Bureaucrat();
     Bureaucrat(const Bureaucrat& other);
     Bureaucrat(const std::string& _name, int _grade);
     Bureaucrat& operator=(const Bureaucrat& other);
     ~Bureaucrat();
     
     int  getGrade() const ;
     std::string getName() const ;
     void incrementGrade();
     void decrementGrade();
    

     /// for 2 class 
    class GradeTooHighException : public std::exception 
    {
        const char* what() const throw()
        { 
            return "Grade too high"; 
        }
    };
    
    class GradeTooLowException : public std::exception 
    {
        const char* what() const throw() 
        { 
            return "Grade too low"; 
        }
    };
    void executeForm(AForm const & form) const {
        try 
        {
            form.execute(*this);
            std::cout << this->getName() << " executed " << form.getName() << std::endl;
        }
        catch (std::exception & e) 
        {
            std::cerr << this->getName() << " couldn't execute " << form.getName() 
                      << " because: " << e.what() << std::endl;
        }
    }
    void signAForm(AForm& AForm);
};

std::ostream &operator<<(std::ostream &os , const Bureaucrat &a);
#endif 