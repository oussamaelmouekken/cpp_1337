#include "Sed_is_for_losers.hpp"

void	replace_in_file(std::string filename, std::string s1, std::string s2)
{
    
    std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
        std::cout << "cannot open file\n";
		return ;
	}
    std::string name_outfile = filename + ".replace";
    std::ofstream outfile(name_outfile.c_str());
    if(!outfile.is_open())
    {
        std::cout << "cannot open outfile\n";
		return ;
    }
	std::string line;
	while (std::getline(file, line))
	{
        size_t pos = 0;
        size_t found_pos = 0;
		while ((found_pos = line.find(s1, pos)) != std::string::npos)
		{
            line.erase(found_pos, s1.length());
            line.insert(found_pos, s2);
            pos = found_pos + s2.length();
        }
        outfile << line;
        if (!file.eof())
        outfile << std::endl;
	}
	file.close();
    outfile.close();
}