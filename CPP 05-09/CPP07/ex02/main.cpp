/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:54:08 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/13 16:02:14 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{
	std::cout << "test 1: default constructor for ints" << std::endl;
	try
	{
		Array<int>	ints;
		for (unsigned int i = 0; i < ints.size(); i++)
			std::cout << ints[i] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "end of test 1" << std::endl;
	std::cout << "test 2: constructor with a parameter of 5" << std::endl;
	try
	{
		Array<int>	ints(5);
		for (unsigned int i = 0; i < ints.size(); i++)
			std::cout << ints[i] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "end of test 2" << std::endl;
	std::cout << "test3 :constructor with a parameter of 5 and call on the 7th" << std::endl;
	try
	{
		Array<int>	ints(5);
		std::cout << ints[7] << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "end of test 3" << std::endl;
	std::cout << "test 4: copies and behaviours" << std::endl;
	try
	{
		Array<int>	ints(5);
		ints[1] = 30;
		std::cout << "printing \033[33marray\033[0m with 30 on i = 1:" << std::endl;
		for (unsigned int i = 0; i < ints.size(); i++)
			std::cout << ints[i] << std::endl;
			
		Array<int>	ints2 = ints;
		std::cout << "printing a \033[35mcopy\033[0m of the \033[33marray\033[0m:" << std::endl;
		for (unsigned int i = 0; i < ints2.size(); i++)
			std::cout << ints2[i] << std::endl;
			
		ints2[2] = 25;
		std::cout << "printing \033[35mcopy\033[0m of \033[33marray\033[0m with 25 on i = 2:" << std::endl;
		for (unsigned int i = 0; i < ints2.size(); i++)
			std::cout << ints2[i] << std::endl;
		std::cout << "printing the \033[33moriginal array\033[0m again:" << std::endl;
		for (unsigned int i = 0; i < ints.size(); i++)
			std::cout << ints[i] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "end of test 4" << std::endl;
	return (0);
}