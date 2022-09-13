#include <iostream>
#include <string>
#include <stack>
#include "MutantStack.hpp"

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

	MutantStack<int>	mlist;

	mlist.push(5);
	mlist.push(17);

	std::cout << mlist.top() << std::endl; mlist.pop();
	
	std::cout << mlist.size() << std::endl;
	
	mlist.push(3);
	mlist.push(5);
	mlist.push(737);
	//[...]
	mlist.push(0);
	
	MutantStack<int>::iterator it2 = mlist.begin();
	MutantStack<int>::iterator it2e = mlist.end();
	
	++it2;
	--it2;
	while (it2 != it2e)
	{
			std::cout << *it2 << std::endl;
	++it2;
	}
//	std::stack<int> s(mstack);
//	std::stack<int> s(mlist);
	return 0;
}
