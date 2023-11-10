/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:11:55 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/02 19:07:38 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		Harl	harl2;
		harl2.filter(av[1]);
		return (0);
	}
	std::cout << "Specify filter: DEBUG, INFO, WARNING, ERROR" << std::endl;
	return (1);
}