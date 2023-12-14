/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:09:44 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/14 14:22:13 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	try
	{
		std::list<int>	intlist;
		intlist.push_back(1);
		intlist.push_back(2);
		intlist.push_back(3);
		intlist.push_back(4);
		easyfind(intlist, 3);
		easyfind(intlist, 10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::vector<int>	intvector;
		intvector.push_back(1);
		intvector.push_back(2);
		intvector.push_back(3);
		intvector.push_back(4);
		easyfind(intvector, 3);
		easyfind(intvector, 10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);	
}