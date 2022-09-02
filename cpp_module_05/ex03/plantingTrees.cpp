#include "ShrubberyCreationForm.hpp"

int	ShrubberyCreationForm::plantingTrees( void ) const
{
	std::string		filename(this->_target + "_shrubbery");
	std::ofstream	outFlux(filename);
	std::string		buffer;
	bool			light_switch(true);

	if (!outFlux)
	{
		std::cerr << "Error: impossible to open the file." << std::endl;
		return (1);
	}
	outFlux << "                                                                                              " << std::endl;
	outFlux << "                                                                                              " << std::endl;
	outFlux << "                   a                                               a                           " << std::endl;
	outFlux << "                  a a                                            a a                           " << std::endl;
	outFlux << "                 a a a                                          a a a                          " << std::endl;
	outFlux << "                a a ia a                                       a a a a                        " << std::endl;
	outFlux << "               a a ia a a                                     a a a a a                      " << std::endl;
	outFlux << "              iai ai a a aa                                  a a a a a a                     " << std::endl;
	outFlux << "             ai aii a a ai aa                                 a a a a a a a                    " << std::endl;
	outFlux << "            a ia ai a a iai ai                                a a a a a a a a                   " << std::endl;
	outFlux << "           a ai a ai a ia ai iaa                             a a a a a a a a a                 " << std::endl;
	outFlux << "          a a iia a ai ia a aii a                          a a a a a a a a a a                " << std::endl;
	outFlux << "         a a ai a ia aiia a a ai g                         a a a a a a a a a a a               " << std::endl;
	outFlux << "        a a ai ia ai a a a a ai aia                      a a a a a a a a a a a a              " << std::endl;
	outFlux << "                 a iia a                               a a a a a a a a a a a a a a            " << std::endl;
	outFlux << "                 a iai a                              a a a a a a a a a a a a a a a           " << std::endl;
	outFlux << "                 a ai ia                            a a a a a a a a a a a a a a a a          " << std::endl;
	outFlux << "                  a iaa                                         a a a                         " << std::endl;
	outFlux << "                  aaiia                                         a a a                         " << std::endl;
	outFlux << "                 a aai a                                        a a a                         " << std::endl;
	outFlux << "                                                                                              " << std::endl;
	return (0);
}
