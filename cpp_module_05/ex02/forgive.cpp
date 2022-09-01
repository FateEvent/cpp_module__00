#include "PresidentialPardonForm.hpp"

void	PresidentialPardonForm::forgive( void ) const
{
	std::cout << " His excellency Zaphod Beeblebrox concedes his pardon to " << this->_target << std::endl;
}