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


	std::list<int>	lst;

	lst.push_back(5);
	lst.push_back(17);

	std::cout << lst.back() << std::endl; lst.pop_back();
	
	std::cout << lst.size() << std::endl;
	
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	//[...]
	lst.push_back(0);
	
	std::list<int>::iterator it3 = lst.begin();
	std::list<int>::iterator ite3 = lst.end();
	
	++it3;
	--it3;
	while (it3 != ite3)
	{
		std::cout << *it3 << std::endl;
		++it3;
	}
	std::list<int> s3(lst);

	return 0;
}
