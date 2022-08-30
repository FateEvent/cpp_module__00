#include <iostream>
#include "Harl.hpp"

int main()
{
	Harl	harl;

	harl.complain("INFO");
	harl.complain("error");
	harl.complain("debug");
	harl.complain("DEBUG");
	harl.complain("boycott");
	harl.complain("WARNING");
	return 0;
}
