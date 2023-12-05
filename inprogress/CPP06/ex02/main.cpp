/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:12:05 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/05 18:52:54 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	std::time_t rNum = std::time(0);
	if (rNum % 3 == 0)
		return (new A());
	else if (rNum % 3 == 1)
		return (new B());
	else
		return (new C());
}

void	identify(Base *p)
{
	std::cout << "The Base type is: ";
	if (dynamic_cast<A*>(p))
		std::cout << "*A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "*B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "*C" << std::endl;
	else
		std::cout << "unknown pointer" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A& referenceA = dynamic_cast<A&>(p);
		std::cout << "The Base type is: &A" << std::endl;
		(void)referenceA;
	}
	catch(std::exception& e)
	{
	}
	try
	{
		B& referenceB = dynamic_cast<B&>(p);
		std::cout << "The Base type is: &B" << std::endl;
		(void)referenceB;
	}
	catch(std::exception& e)
	{
	}
	try
	{
		C& referenceC = dynamic_cast<C&>(p);
		std::cout << "The Base type is: &C" << std::endl;
		(void)referenceC;
	}
	catch(std::exception& e)
	{
	}
	
}

int	main(void)
{
	Base *someclass = generate();
	identify(someclass);
	identify(*someclass);
	delete someclass;
	return (0);
}