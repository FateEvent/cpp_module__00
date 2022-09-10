/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:04:58 by faventur          #+#    #+#             */
/*   Updated: 2022/09/10 21:06:24 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "detect.hpp"

Base	*generate(void)
{
	typedef std::chrono::high_resolution_clock	myclock;

	myclock::time_point beginning = myclock::now();
	myclock::duration d = myclock::now() - beginning;
	unsigned seed = d.count();

	std::default_random_engine	generator(seed);
	std::uniform_int_distribution<int>	distribution(0, 2);

	int	toak = distribution(generator);
	switch (toak)
	{
	case 0:
		return new A();
	case 1:
		return new B();
	default:
		return new C();
	}
}

void	identify( Base *p )
{
	A	*a;
	if ((a = dynamic_cast<A *>(p)))
		std::cout << "A" << std::endl;
	B	*b;
	if ((b = dynamic_cast<B *>(p)))
		std::cout << "B" << std::endl;
	C	*c;
	if ((c = dynamic_cast<C *>(p)))
		std::cout << "C" << std::endl;
}

void	identify( Base &p )
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e)
	{
		(void)e;
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e)
	{
		(void)e;
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e)
	{
		(void)e;
	}
}
