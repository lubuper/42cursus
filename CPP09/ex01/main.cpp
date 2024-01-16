/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:50:58 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/29 20:58:33 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (std::cout << "Error: invalid input" << std::endl, 1);
	try
	{
		std::string	parameters = av[1];
		RPN	rpn;
		rpn.fillstack(parameters);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);	
}