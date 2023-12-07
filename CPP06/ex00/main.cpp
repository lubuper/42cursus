/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:40:55 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/04 17:24:57 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1 && std::cout << "Invalid: You must only have one input (spaces delimits your input)" << std::endl);
	int	i = 0;
	std::string const input = av[1];
	while (input[i])
	{
		if (input[i] < 32 || input[i] > 126)
			return (2 && std::cout << "Invalid: You must have a displayable input" << std::endl);
		i++;
	}
	ScalarConverter::convert(input);
	return (0);
}