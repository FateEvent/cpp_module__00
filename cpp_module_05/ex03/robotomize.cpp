#include "RobotomyRequestForm.hpp"

void	RobotomyRequestForm::robotomize( void ) const
{
	typedef std::chrono::high_resolution_clock	myclock;

	myclock::time_point beginning = myclock::now();
	myclock::duration d = myclock::now() - beginning;
	unsigned seed = d.count();

	std::default_random_engine					generator(seed);
	std::uniform_int_distribution<int>			distribution(0,1);

	int lightSwitch = distribution(generator);
	std::cout << "* LOUD AND ANNOYING DRILLING NOISE *" << std::endl;
	if (lightSwitch)
		std::cout << this->_target << " has been robotomized." << std::endl;
	else
		std::cout << this->_target << " has not been robotomized." << std::endl;
}