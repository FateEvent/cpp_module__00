#ifndef SERIALIZE_H
# define SERIALIZE_H

# include <iostream>
# include <string>

typedef struct s_data {
	std::string	data;
}							Data;

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);

#endif