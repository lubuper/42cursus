/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:37:37 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/20 22:04:54 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int	size;
	std::cout << "How many zombies does your Horde have?" << std::endl;
	std::cout << "> ";
	std::cin >> size;
	if (size < 0)
	{
		std::cout << "You've made " << -size << " humans" << std::endl;
		return (1);
	}
	Zombie	*zHorde = zombieHorde(size, "Imhotep");
	for (int i = 0; i < size; i++)
		zHorde[i].announce();
	delete[] zHorde;
	return (0);
}