#include "PhoneBook_contacts.hpp"

int main(int ac, char **av)
{
    PhoneBook PhoneBook;
    (void )av;
    if(ac > 1)
    {
        std::cout<<"invalide arguments\n";
        return 0;
    }
    std::string input;
    while(1)
    {
        std::cout << Blue"entre one of the command(ADD | SEARCH | EXIT):" RESET;
        std::cin >> input;
        if (std::cin.eof())
		{
			std::cout << "\nInput terminated (Ctrl+D detected). Exiting search.\n";
			exit(0);
		}
        if(input == "ADD")
        {
            PhoneBook.add_contact();
        }
        else if (input == "SEARCH")
        {
            PhoneBook.search_contact();
        }
        else if(input == "EXIT")
        {
            break;
        }
        else 
        {
            std::cout <<"invalid input"<< std::endl;
        }
    }
}