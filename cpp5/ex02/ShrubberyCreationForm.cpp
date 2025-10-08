#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery Creation Form", 145, 137), target(target)
{
    std::cout<<"Shrubbery Creation Form constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target)
{
    std::cout<<"Shrubbery Creation Form copy constructor called\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        this->target = other.target;
    }
    std::cout<<"Shrubbery Creation Form copy assignement constructor called\n";
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout<<"Shrubbery Creation Form destructor called\n";
}

void  ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    (void) executor;
    std::string file_name = this->target + "_shrubbery";
    std::ofstream file(file_name.c_str());
    if(!file.is_open())
    {
       throw std::runtime_error("the file cannot open " + file_name);
    }
    file << "       *\n"
    << "      ***\n"
    << "     *****\n"
    << "    *******\n"
    << "      |||\n"
    << "      |||\n"
    << "     //|\\\\\n";
    file.close();
}
