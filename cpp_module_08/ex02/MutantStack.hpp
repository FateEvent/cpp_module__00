#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

# include <iostream>
# include <stack>
# include <list>

template <typename T>
class	MutantStack : public std::stack<T>
{
	public:
		MutantStack() { }

		MutantStack(const MutantStack& src) {
			*this = src;
		}

		~MutantStack(void) { };

		MutantStack&	operator = (const MutantStack& rhs) {
			this->c = rhs.c;
			return (*this);
		}

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator	begin()	{ return (this->c.begin()); }
		iterator	end()	{ return (this->c.end()); }
};

#endif