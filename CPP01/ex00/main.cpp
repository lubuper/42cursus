/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:37:37 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/20 19:53:34 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::string	zombie1_name;
	std::string	zombie2_name;
	std::cout << "Name the first Zombie: ";
	std::cin >> zombie1_name;
	Zombie	*zombie_1 = newZombie(zombie1_name);
	zombie_1->announce();
	std::cout << "Name the second Zombie: ";
	std::cin >> zombie2_name;
	randomChump(zombie2_name);
	delete zombie_1;
	return (0);
}