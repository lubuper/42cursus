/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:34:25 by lde-sous          #+#    #+#             */
/*   Updated: 2024/01/08 19:28:16 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac < 2)
		return (std::cout << "Error: must have input" << std::endl, 1);
	for (int i = 1; i < ac; i++)
	{
		if (std::atol(av[i]) < 0 || std::atol(av[i]) > INT_MAX || std::atol(av[i]) < INT_MIN)
			return (std::cout << "Error: input is not a valid positive integer" << std::endl, 1);
		for (int j = 0; av[i][j] != 0; j++)
		{
			if (!isdigit(av[i][j]))
				return (std::cout << "Error: invalid input" << std::endl, 1);
		}
	}
	PmergeMe	input(ac, av);
	input.sort_and_compare();
	return (0);
}