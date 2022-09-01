#include "ShrubberyCreationForm.hpp"

int	plantingTrees( std::string target )
{
	std::string		filename(target + "_shrubbery");
	std::ofstream	outFlux(filename);
	std::string		buffer;
	bool			light_switch(true);

	if (!outFlux)
	{
		std::cerr << "Error: impossible to open the file." << std::endl;
		return (1);
	}
	outFlux << "                   a                                            a                         " << std::endl;
	outFlux << "                  a a                                          a a                        " << std::endl;
	outFlux << "                 a a a                                        a a a                       " << std::endl;
	outFlux << "                a a a a                                      a a a a                      " << std::endl;
	outFlux << "               a a a a a                                    a a a a a                     " << std::endl;
	outFlux << "              a a a a a a                                  a a a a a a                    " << std::endl;
	outFlux << "             a a a a a a a                                a a a a a a a                   " << std::endl;
	outFlux << "            a a a a a a a a                              a a a a a a a a                  " << std::endl;
	outFlux << "           a a a a a a a a a                            a a a a a a a a a                 " << std::endl;
	outFlux << "          a a a a a a a a a a                          a a a a a a a a a a                " << std::endl;
	outFlux << "         a a a a a a a a a a a                        a a a a a a a a a a a               " << std::endl;
	outFlux << "        a a a a a a a a a a a a                      a a a a a a a a a a a a              " << std::endl;
	outFlux << "                 a a a                              a a a a a a a a a a a a a             " << std::endl;
	outFlux << "                  a a                              a a a a a a a a a a a a a a            " << std::endl;
	outFlux << "                 a a a                            a a a a a a a a a a a a a a a           " << std::endl;
	outFlux << "                  a a                                         a a a                       " << std::endl;
	outFlux << "                  a a                                         a a a                       " << std::endl;
	outFlux << "                 a a a                                        a a a                       " << std::endl;
	return (0);
}
