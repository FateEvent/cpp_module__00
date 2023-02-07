#include "MutantStack.hpp"
#include <list>

int main()
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl; mstack.pop();
	
	std::cout << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s1(mstack);


	MutantStack<int, std::list<int> >	mlist;

	mlist.push(5);
	mlist.push(17);

	std::cout << mlist.top() << std::endl; mlist.pop();
	
	std::cout << mlist.size() << std::endl;
	
	mlist.push(3);
	mlist.push(5);
	mlist.push(737);
	//[...]
	mlist.push(0);
	
	MutantStack<int, std::list<int> >::iterator it2 = mlist.begin();
	MutantStack<int, std::list<int> >::iterator it2e = mlist.end();
	
	++it2;
	--it2;
	while (it2 != it2e)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	std::stack<int, std::list<int> > s2(mlist);

	return 0;
}
