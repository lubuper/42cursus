/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:39:50 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/21 19:14:53 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void	test1(void)
{
	std::cout << "---Test 1: adding a number to a Span class with 0 storage---" << std::endl;
		try
		{
			Span	test1 = Span();	
			test1.addNumber(5);
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	std::cout << "-----------------------end of Test 1------------------------" << std::endl;
}

void	test2(void)
{
	std::cout << "Test 2 : Span class with 5 storage capacity. Add 6 3 17 9 and 11" << std::endl;
	try
	{
		Span	test2 = Span(5);
		test2.addNumber(6);
		test2.addNumber(3);
		test2.addNumber(17);
		test2.addNumber(9);
		test2.addNumber(11);
		std::cout << "shortest span: " << test2.shortestSpan() << std::endl;
		std::cout << "longest span: " <<test2.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "---------------------------end of Test 2----------------------------" << std::endl;	
}

void	test3(void)
{
		std::cout << "---Test 3: trying to get the short span out of a 1 value vector-----" << std::endl;
	try
	{
		Span test3 = Span(4);
		test3.addNumber(4);
		test3.addNumber(4);
		test3.addNumber(4);
		test3.addNumber(4);
		std::cout << "shortest span: " << test3.shortestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "---------------------------end of Test 3----------------------------" << std::endl;
}

void	test4(void)
{
	std::cout << "---Test 4: trying to get the long span out of a 1 value vector-----" << std::endl;
	try
	{
		Span test4 = Span(4);
		test4.addNumber(4);
		test4.addNumber(4);
		test4.addNumber(4);
		test4.addNumber(4);
		std::cout << "longest span: " << test4.longestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "---------------------------end of Test 4----------------------------" << std::endl;
}

void	test5(void)
{
	std::cout << "------------Test 5: Using the fillSpan member function-------------" << std::endl;
	try
	{
		Span test5 = Span(20);
		int	arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9 , 10};
		int arr2[] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
		test5.fillSpan(arr, arr + sizeof(arr) / sizeof(int));
		test5.fillSpan(arr2, arr2 + sizeof(arr2) / sizeof(int));
		/*arr and arr2 are arrays, and in C++, arrays can be used with pointer arithmetic to form a range.
		arr is a pointer to the first element of the array, and arr + sizeof(arr) / sizeof(int) is a pointer
		to one past the end of the array. This forms a valid range [begin, end].*/
		std::cout << "shortest span: " << test5.shortestSpan() << std::endl;
		std::cout << "longest span: " << test5.longestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "---------------------------end of Test 5----------------------------" << std::endl;
}

int main(void)
{
	test1();
	std::cout << std::endl;
	test2();
	std::cout << std::endl;
	test3();
	std::cout << std::endl;
	test4();
	std::cout << std::endl;
	test5();
	return 0;
}