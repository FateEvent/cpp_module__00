#include <iostream>
#include "Harl.hpp"

int main(int ac, char *av[])
{
    Harl        harl;
    std::string str;
    int         input;

    if (ac == 1 || ac > 2)
    {
        std::cerr << "Invalid number of arguments!" << std::endl;
        return (1);
    }
    str = av[1];
    input = -1;
    if (str == "ERROR")
        input = 0;
    else if (str == "WARNING")
        input = 1;
    else if (str == "INFO")
        input = 2;
    else if (str == "DEBUG")
        input = 3;
    switch (input) {
    case 0:
        harl.complain("ERROR");
        break;
    case 1:
        harl.complain("WARNING");
        harl.complain("ERROR");
        break;
    case 2:
        harl.complain("INFO");
        harl.complain("WARNING");
        harl.complain("ERROR");
        break;
    case 3:
        harl.complain("DEBUG");
        harl.complain("INFO");
        harl.complain("WARNING");
        harl.complain("ERROR");
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
    return (0);
}
