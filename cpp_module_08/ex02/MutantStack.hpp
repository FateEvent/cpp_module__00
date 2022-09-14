#include <iostream>
#include <deque>
#include "ArrayException.hpp"

template <class T, class Container = std::deque<T> >
class MutantStack
{
protected:
		Container	_c;

public:
		typedef Container																	container_type;
		typedef typename container_type::value_type				value_type;
		typedef typename container_type::reference				reference;
		typedef typename container_type::const_reference	const_reference;
		typedef typename container_type::size_type				size_type;

		MutantStack(): _c() {}

		MutantStack(const MutantStack& q) : _c(q._c) {}

		~MutantStack(void) {};

		MutantStack&	operator = (const MutantStack& q) { _c = q._c; return *this; }

		bool	empty()	const { return _c.empty(); }

		size_type	size()	const { return _c.size(); }

		reference	top(void) { return _c.back(); }

		void	push(const value_type& v)	{ _c.push_back(v); }

		void	pop()	{ _c.pop_back(); }

		void swap(MutantStack & ms)
		{
				swap(_c, ms._c);
		};

		typedef struct Iterator
		{
				Iterator(int	*ptr) : _ptr(ptr) {}

				int	&operator*() const { return *_ptr; }
				int	*operator->() { return _ptr; }

				// Prefix increment
				Iterator& operator++() { _ptr++; return *this; }

				// Postfix increment
				Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }

				Iterator&	operator--() { _ptr--; return *this; }
				Iterator	operator--(int) { Iterator tmp = *this; --(*this); return tmp; }

				bool operator== (const Iterator& it) { return this->_ptr == it._ptr; };
				bool operator!= (const Iterator& it) { return this->_ptr != it._ptr; };

		private:
				int	*_ptr;

		}								iterator;

		Iterator	begin()	{ return Iterator(&_c[0]); }
		Iterator	end()		{ return Iterator(&_c[_c.size()]); }
};

template <class T, class Container>
	bool operator==(const MutantStack<T, Container>& x, const MutantStack<T, Container>& y);
template <class T, class Container>
	bool operator< (const MutantStack<T, Container>& x, const MutantStack<T, Container>& y);
template <class T, class Container>
	bool operator!=(const MutantStack<T, Container>& x, const MutantStack<T, Container>& y);
template <class T, class Container>
	bool operator> (const MutantStack<T, Container>& x, const MutantStack<T, Container>& y);
template <class T, class Container>
	bool operator>=(const MutantStack<T, Container>& x, const MutantStack<T, Container>& y);
template <class T, class Container>
	bool operator<=(const MutantStack<T, Container>& x, const MutantStack<T, Container>& y);