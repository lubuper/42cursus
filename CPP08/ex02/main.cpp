/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:56:49 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/21 19:00:31 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

void	testMutant(void)
{
	MutantStack<int> mstack;

	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
	mstack.push(4);
	mstack.push(5);
	std::cout << "\e[1;31mMu\e[1;32mTaN\e[1;33mt \e[1;34mStA\e[1;35mcK\e[1;0m of \e[1;31mINTS\e[1;0m created and \e[1;33m1 2 3 4 5\e[1;0m pushed to it." << std::endl;
	std::cout << std::endl;
	std::cout << "\e[1;96mtop\e[1;0m of the stack (aka last int inserted): \e[1;33m" << mstack.top() << std::endl;
	std::cout << std::endl;
	std::cout << "\e[1;31mpopped out\e[1;0m last number inserted (aka \e[1;96mtop\e[1;0m)" << std::endl;
	std::cout << std::endl;
	mstack.pop();
	std::cout << "Stack size by calling \e[1;34m.size()\e[1;0m is: \e[1;33m" <<mstack.size() << std::endl;
	std::cout << std::endl;
	mstack.push(3);
	mstack.push(6);
	mstack.push(737);
	mstack.push(0);
	std::cout << "\e[1;33mPushed \e[1;33m3 6 737\e[1;0m and \e[1;33m0\e[1;0m to the stack." << std::endl;
	std::cout << std::endl;

	MutantStack<int>::iterator it1 = mstack.it_begin();
	MutantStack<int>::iterator it2 = mstack.it_end();

	std::cout << "Iterating \e[1;31m<int> \e[1;31mMu\e[1;32mTaN\e[1;33mt \e[1;34mStA\e[1;35mcK...\e[1;0m" << std::endl;
	while (it1 != it2) {
		std::cout << *it1 << std::endl;
		++it1;
	}
	std::cout << "Iteration \e[1;32m\e[1;5mcomplete!\e[1;0m" << std::endl;
}

void	testList(void)
{
	std::list<int> list1;

	list1.push_back(1);
	list1.push_back(2);
	list1.push_back(3);
	list1.push_back(4);
	list1.push_back(5);
	std::cout << "\e[1;32mLIST of \e[1;31mINTS\e[1;0m created and \e[1;33m1 2 3 4 5\e[1;0m pushed to it." << std::endl;
	std::cout << std::endl;
	std::cout << "\e[1;96mback\e[1;0m of the stack (aka last list inserted): \e[1;33m" << list1.back() << std::endl;
	std::cout << std::endl;
	std::cout << "\e[1;31mpopped back\e[1;0m last number inserted (aka \e[1;96mback\e[1;0m)" << std::endl;
	std::cout << std::endl;
	list1.pop_back();
	std::cout << "Stack size by calling \e[1;34m.size()\e[1;0m is: \e[1;33m" << list1.size() << std::endl;
	std::cout << std::endl;
	list1.push_back(3);
	list1.push_back(6);
	list1.push_back(737);
	list1.push_back(0);
	std::cout << "\e[1;33mPushed \e[1;33m3 6 737\e[1;0m and \e[1;33m0\e[1;0m to the stack." << std::endl;
	std::cout << std::endl;

	std::list<int>::iterator it1 = list1.begin();
	std::list<int>::iterator it2 = list1.end();

	std::cout << "Iterating \e[1;31m<int> \e[1;32mLIST...\e[1;0m" << std::endl;
	while (it1 != it2) {
		std::cout << *it1 << std::endl;
		++it1;
	}
	std::cout << "Iteration \e[1;32m\e[1;5mcomplete!\e[1;0m" << std::endl;	
}

int	main(void)
{
	std::cout << "--------------------------------------------------------------------------------" << std::endl;
	testMutant();
	std::cout << "--------------------------------------------------------------------------------" << std::endl;
	testList();
	return 0;
}