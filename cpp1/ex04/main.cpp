#include "Sed_is_for_losers.hpp"

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "invalid input \n";
		return (0);
	}
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	replace_in_file(filename, s1, s2);
	return (0);
}
