#ifndef BUREAUCRAT_CPP
#define BUREAUCRAT_CPP
#include <iostream>
#include <ostream>
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
};

std::ostream &operator<<(std::ostream &os , const Bureaucrat &a);
#endif 