#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char *av[])
{
	if (ac < 4 || ac > 4)
	{
		std::cerr << "Invalid number of arguments!" << std::endl;
		return (1);
	}
	std::ifstream	inFlux(av[1]);
	std::string		filename(av[1]);
	filename += ".replace";
	std::ofstream	outFlux(filename);
	std::string		buffer;
	std::string		s1(av[2]);
	std::string		s2(av[3]);
	bool			light_switch(true);

	if (!inFlux || !outFlux)
	{
		std::cerr << "Error: impossible to open the file." << std::endl;
		return (1);
	}
	while (getline(inFlux, buffer))
	{
		std::string::size_type	i(0);
		std::string::size_type	pos = buffer.find(s1);
		while (i < pos && buffer[i] != '\0')
		{
			outFlux.put(buffer[i]);
			i++;
		}
		if (buffer[i] == '\0')
			outFlux.put('\n');
		while (pos != std::string::npos)
		{
			outFlux << s2;
			i += s1.length();
			pos = buffer.find(s1, pos + 1);
			while (i < pos && buffer[i] != '\0')
			{
				outFlux.put(buffer[i]);
				i++;
			}
			if (buffer[i] == '\0')
				outFlux.put('\n');
		}
	}
	return 0;
}
