#ifndef ITER_H
# define ITER_H

# include <iostream>

template<typename T>
void	display(T element) {
	std::cout << element << std::endl;
}

template<typename T>
void	iter(T *arr, size_t size, void (*f)(T const &)) {
	size_t	i(0);

	while (i < size)
		f(arr[i++]);
}

#endif