#include "PhoneBook_contacts.hpp"

void Contact::set_data(std::string &data)
{
    std::cin >> data;
    if (std::cin.eof())
	{
        std::cout << "\nInput terminated (Ctrl+D detected). Exiting search.\n";
		exit(0);
	}
}

void Contact::set_contact()
{
	std::cout << "Enter First Name: ";
    set_data(first_name);
	std::cout << "Enter Last Name: ";
	set_data(last_name);
	std::cout << "Enter Nickname: ";
	set_data(nickname);
	std::cout << "Enter Phone Number: ";
	set_data(phone_number);
	std::cout << "Enter Darkest Secret: ";
	set_data(darkest_secret);
}

std::string Contact::get_first_name()
{
	return (first_name);
}

std::string Contact::get_last_name()
{
	return (last_name);
}

std::string Contact::get_nickname()
{
	return (nickname);
}
std::string Contact::get_phonenumber()
{
	return (phone_number);
}
std::string Contact::get_secret()
{
	return (darkest_secret);
}
std::string valide_string(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}
void Contact::display_contacts()
{
	std::cout << "| " << std::setw(10) << valide_string(get_first_name());
	std::cout << "| " << std::setw(10) << valide_string(get_last_name());
	std::cout << "| " << std::setw(10) << valide_string(get_nickname()) << "|\n";
}

void Contact::display_one_contacts()
{
	std::cout << Blue " first name: " RESET << get_first_name() << std::endl;
	std::cout << Blue " last name: " RESET << get_last_name() << std::endl;
	std::cout << Blue " nick name: " RESET << get_nickname() << std::endl;
	std::cout << Blue " phone number: " RESET << get_phonenumber() << std::endl;
	std::cout << Blue " darkest secret: " RESET << get_secret() << std::endl;
}