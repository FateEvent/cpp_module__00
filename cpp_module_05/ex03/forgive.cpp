#include "PresidentialPardonForm.hpp"

void	PresidentialPardonForm::forgive( void ) const
{
	std::cout << "His excellency Zaphod Beeblebrox granted his long-awaited pardon to " << this->_target << std::endl;
}