#include <fstream>
#include <iostream>


int replace(char **av, std::string str)
{
	std::ofstream WFile((std::string(av[1]) + ".replace").c_str());
	int	pos;

	if (!WFile)
		return (0);
	for (int i = 0; i < (int)str.size(); i++)
	{
		pos = str.find(av[2], i);
		if (pos != -1 && pos == i)
		{
			WFile << av[3];
			i += std::string(av[2]).size() - 1;
		}
		else
			WFile << str[i];
	}
	return(0);
}

int main(int ac, char **av)
{
	char	c;
	std::ifstream	RFile;
	std::string	str;
	if (ac != 4)
	{
		std::cout << "it must contains <filename> <string 1> <string 2> as arguments \n" << std::endl;
		return (0);
	}
 	RFile.open(av[1]);
 	if (!RFile)
 	{
 		std::cerr << "Error: cannot open the file\n" << std::endl;
 		return (0);
 	}
 	while (!RFile.eof() && RFile >> std::noskipws >> c)
 		str += c;
 	replace(av, str);
 	return 0;
}
