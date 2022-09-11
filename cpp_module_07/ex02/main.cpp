#include "iter.hpp"
#include "Array.hpp"

int	main()
{
	/*
	int	arr[5] = {1, 4, 6, 6, 3};
	std::string	tab[6] = {"mamma", "mia", "here", "we", "go", "again"};
	float	grid[5] = {1.6, 4, 8.67f, 6, 3.0f};
	*/

	::Array<int> arr;
	::Array<> tab(5);

	try
	{
		std::cout << tab[5] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	
/*
	::iter(arr, 5, display);
	std::cout << std::endl << "- - - - - - - - -" << std::endl;
	::iter(tab, 6, display);
	std::cout << std::endl << "- - - - - - - - -" << std::endl;
	::iter(grid, 5, display);
	*/
}