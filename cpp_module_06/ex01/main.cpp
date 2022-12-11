#include <iostream>
#include "serialize.hpp"

int	main()
{
	Data	*ptr = new Data;

	ptr->data = "Hello, worlds!";
	
	uintptr_t	raw = serialize(ptr);
	Data		*dPtr = deserialize(raw);

	std::cout << dPtr->data << std::endl;
}

uintptr_t	serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
