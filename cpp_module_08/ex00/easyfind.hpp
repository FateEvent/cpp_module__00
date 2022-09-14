#ifndef EASYFIND_H
# define EASYFIND_H

# include <iostream>
# include <string>
# include <vector>
# include <list>
# include <algorithm>
# include "ArrayException.hpp"

template <typename T>
const int	easyfind(T container, int n)
{
	typename T::iterator	it = std::find(container.begin(), container.end(), n);

	if (it != container.end())
		return (std::distance(container.begin(), it));
	throw ArrayException("NumberNotFoundException");
}

#endif