#ifndef AForm_H
#define AForm_H
#include <iostream>
#include <ostream>
//class Bureaucrat;

#define HEIGHT_GRADE 1
#define LOW_GRADE 150

class Bureaucrat;

class AForm
{
    private :
        const std::string name;
        bool signed_status;
        const int gradeRequiredToSign;
        const int gradeRequiredToExecute;
     public :
     AForm();
     AForm(const std::string& name, int gradeToSign, int gradeToExecute);
     AForm(const AForm& other);
     AForm& operator=(const AForm& other);
    virtual ~AForm();

     void beSigned(const Bureaucrat& bureaucrat);
     /// for getters 
     const std::string& getName() const;
     bool is_signed() const;
     int getgrade_tosign() const;
     int getgrade_toexecute() const;

     /// 
     int getGradeRequiredToSign() const;
     int getGradeRequiredToExecute() const;
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
     virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &os , const AForm &a);
#endif