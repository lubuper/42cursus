/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:55:50 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/07 16:05:27 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	clappy("clappy");

	clappy.attack("trash bin");
	clappy.attack("clappy");
	clappy.takeDamage(2);
	clappy.beRepaired(1);
	clappy.beRepaired(1);
	clappy.beRepaired(100);
	clappy.attack("Traveler");
	clappy.takeDamage(100);
	clappy.beRepaired(10);
	
	return (0);
}