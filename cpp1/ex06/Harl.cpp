#include "Harl.hpp"

void Harl::debug()
{
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void Harl::info()
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did,I wouldn’t be asking for more!\n";
}

void Harl::warning()
{
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error()
{
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level)
{
	int levelIndex = 5;
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			levelIndex = i;
			break ;
		}
	}
	switch (levelIndex)
	{
	case 0:
		debug();
        info();
        warning();
        error();
        break;
	case 1:
		info();
        warning();
        error();
        break;
	case 2:
		warning();
        error();
        break;
	case 3:
		error();
		break ;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}