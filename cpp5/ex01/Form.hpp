#ifndef FORM_H
#define FORM_H
#include <iostream>
#include <ostream>
//class Bureaucrat;

#define HEIGHT_GRADE 1
#define LOW_GRADE 150
class Bureaucrat;
class Form
{
    private :
        const std::string name;
        bool signed_status;
        const int gradeRequiredToSign;
        const int gradeRequiredToExecute;
     public :

    Form();
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();
    
     void beSigned(const Bureaucrat& bureaucrat);
     /// for getters 
     const std::string& getName() const;
     bool is_signed() const;
     int getgrade_tosign() const;
     int getgrade_toexecute() const;
     
     /// for exception 
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

std::ostream &operator<<(std::ostream &os , const Form &a);
#endif