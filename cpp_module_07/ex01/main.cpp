#include "iter.hpp"

class Awesome
{
public:
	Awesome( void ) : _n( 42 ) { return; }
	int	get( void ) const { return this->_n; }

private:
	int _n;
};

std::ostream &operator<<(std::ostream &o, const Awesome &a) { return (o << a.get()); }

template <typename T>
void print( T const & x ) { std::cout << x << std::endl; return; }


int	main()
{
	int	arr[5] = {1, 4, 6, 6, 3};
	std::string	tab[6] = {"mamma", "mia", "here", "we", "go", "again"};
	float	grid[5] = {1.6, 4, 8.67f, 6, 3.0f};

	::iter(arr, 5, display);
	std::cout << std::endl << "- - - - - - - - -" << std::endl;
	::iter(tab, 6, display);
	std::cout << std::endl << "- - - - - - - - -" << std::endl;
	::iter(grid, 5, display);

	std::cout << std::endl << "- - - - - - - - -" << std::endl;
	int tb[] = {0, 1, 2, 3, 4}; // <--- I never understood why you can 't write int[] tab. Wouldn' t that make more sense ? 
	Awesome tab2[5];
	iter(tb, 5, print);
	iter(tab2, 5, print);

	return (0);
}
