#include "Span.hpp"

Span::Span( void ) : _capacity(1), _arr(0), _current(0) { }

Span::Span( unsigned capacity ) : _capacity(capacity), _arr(0), _current(0) { }

Span::Span( const Span& src ) : _capacity(src._capacity) { }

Span&	Span::operator=( const Span& rhs ) {
		_capacity = rhs._capacity;
		return (*this);
	}

Span::~Span( void ) { }

void Span::addNumber( unsigned data ) {
	try {
		if (_current == _capacity)
			throw (ArrayException("Span::MaximumCapacityLimitExcedeedException"));
		else {
			_arr.push_back(data);
			_current++;
		}
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}	

int&	Span::getValue( unsigned const & index ) {
	if (index < _arr.size())
		return _arr[index];
	throw (ArrayException("Span::InvalidIndexException"));
}

int&	Span::operator[]( unsigned const & index ) {
	if (index >= _arr.size() )
		throw ArrayException("Array::InvalidIndexException");
	return (_arr[index]);
}

std::size_t	Span::getSize( void ) { return _arr.size(); }

unsigned	Span::getCapacity( void ) { return _capacity; }

void Span::print( void )
{
	for (std::vector<int>::const_iterator it = _arr.begin(); it != _arr.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

unsigned int	Span::shortestSpan( void ) {
	std::vector<int>					tmp(_arr);
	std::vector<int>::const_iterator	it;
	std::vector<int>::const_iterator	it2;
	int									distance;

	if (_arr.size() == 0)
		throw ArrayException("Array::EmptyArrayException");
	if (_arr.size() == 1)
		throw ArrayException("Array::OnlyOneElementException");
	distance = tmp[1] - tmp[0];
	std::sort(tmp.begin(), tmp.end());
	for(int i = 1; i < tmp.size() - 1; i++) {
		if (distance > tmp[i + 1] - tmp[i])
			distance = tmp[i + 1] - tmp[i];
	}
	return (distance);
}

unsigned int	Span::longestSpan( void ) {
	std::vector<int>::const_iterator	it;
	std::vector<int>::const_iterator	it2;

	if (_arr.size() == 0)
		throw ArrayException("Array::EmptyArrayException");
	if (_arr.size() == 1)
		throw ArrayException("Array::OnlyOneElementException");
	it = min_element(_arr.begin(), _arr.end());
	int i = static_cast<int>(*it);
	it2 = max_element(_arr.begin(), _arr.end());
	int i2 = static_cast<int>(*it2);

	return (i2 - i);
}

struct c_unique {
	int current;
	c_unique() { current = 0; }
	int operator()() { return (++current); }
}				UniqueNumber;

static int	RandomNumber () { return (std::rand() % 100); }

void	Span::addManyANumber( void ) {
	std::srand (unsigned(std::time(0)));
	for (std::size_t i = 0; i < _capacity; i++)
		this->addNumber(RandomNumber());
}
