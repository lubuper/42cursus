/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:54:52 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/28 16:37:50 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: Wrong Input" << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange	btc;
		btc.treatDb();
		btc.treatInput((av[1]));
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}