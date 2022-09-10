#ifndef DETECT_H
# define DETECT_H

# include <iostream>
# include <random>
# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base	*generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif
