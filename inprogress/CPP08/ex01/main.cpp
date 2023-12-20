/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:39:50 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/19 16:19:28 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
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
	std::cout << "Test 2 : Span class with 5 storage capacity. Add 5" << std::endl;
	try
	{
		Span	test2 = Span(5);
		test2.addNumber(6);
		test2.addNumber(3);
		test2.addNumber(17);
		test2.addNumber(9);
		test2.addNumber(11);
		std::cout << test2.shortestSpan() << std::endl;
		std::cout << test2.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "---------------------------end of Test 2----------------------------" << std::endl;
	std::cout << "---Test 3: trying to get the short span out of a 1 value vector-----" << std::endl;
	try
	{
		Span test3 = Span(4);
		test3.addNumber(4);
		test3.addNumber(4);
		test3.addNumber(4);
		test3.addNumber(4);
		std::cout << test3.shortestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "---------------------------end of Test 3----------------------------" << std::endl;
	std::cout << "---Test 4: trying to get the long span out of a 1 value vector-----" << std::endl;
	try
	{
		Span test4 = Span(4);
		test4.addNumber(4);
		test4.addNumber(4);
		test4.addNumber(4);
		test4.addNumber(4);
		std::cout << test4.longestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "---------------------------end of Test 3----------------------------" << std::endl;
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
		std::cout << test5.shortestSpan() << std::endl;
		std::cout << test5.longestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "---------------------------end of Test 5----------------------------" << std::endl;
	return 0;
}