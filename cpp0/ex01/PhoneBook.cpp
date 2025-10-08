#include "PhoneBook_contacts.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
	count_contact = 0;
}

void PhoneBook::add_contact()
{
	if (count_contact < 8)
	{
		count_contact++;
		index = (count_contact - 1) % 8;
	}
	else
		index = (index + 1) % 8;
	Contacts[index].set_contact();
	std::cout << Green "📖 Contact added successfully!" RESET << std::endl;
}

void PhoneBook::search_contact()
{
	int new_index = 0;
	if (count_contact == 0)
	{
		std::cout << Blue "🔎 No contacts available!" << std::endl;
		return ;
	}
	std::string id;
	std::cout << Blue "Display all contacts : " RESET << std::endl;
	std::cout << "| " << std::setw(10) << std::left << "Index"
				<< "| " << std::setw(10) << "first name"
				<< "| " << std::setw(10) << "last name"
				<< "| " << std::setw(10) << "nickname"
				<< "|\n" RESET;
	int i = 0;
	while (i < count_contact)
	{
		std::cout << "| " << std::setw(10) << (i + 1);
		Contacts[i].display_contacts();
		i++;
	}
	std::cout << "entre the index of the contact: ";
	std::cin >> new_index;
	while (1)
	{
		if (std::cin.eof())
		{
			std::cout << "\nInput terminated (Ctrl+D detected). Exiting search.\n";
			exit(0);
		}
		if (std::cin.fail() || new_index <= 0 || new_index > count_contact)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid index. Please enter a valid index (1 to " << count_contact << "): ";
			std::cin >> new_index;
		}
		else
		{
			std::cout << "📞 Contact Details:\n";
			Contacts[new_index - 1].display_one_contacts();
			break ;
		}
	}
}