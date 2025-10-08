#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() 
{
    try 
    {
        // Create bureaucrats
        Bureaucrat highRank("CEO", 1);
        Bureaucrat lowRank("Intern", 150);
        
        // Create forms
        Form important("Important Document", 5, 5);
        Form basic("Basic Form", 100, 100);
        
        std::cout << "--- Initial Forms ---\n";
        std::cout << important << std::endl;
        std::cout << basic << std::endl;
        
        std::cout << "\n--- Signing Attempts ---\n";
        // CEO can sign important document
        highRank.signForm(important);
        highRank.signForm(important);
        highRank.signForm(important);

        // Intern can't sign important document
        lowRank.signForm(important);
        
        // Intern can't sign basic form
        lowRank.signForm(basic);
        
        std::cout << "\n--- Final Forms ---\n";
        std::cout << important << std::endl;
        std::cout << basic << std::endl;
        
        // Try to create invalid form (should throw exception)
        //Form invalid("Invalid", 151, 1);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
