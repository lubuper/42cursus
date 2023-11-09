/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:55:50 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/08 11:26:23 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	clappy("clappy");
	ScavTrap	scavvie("scavvie");

	scavvie.sysCheck();
	scavvie.attack("car");
	scavvie.takeDamage(10);
	scavvie.sysCheck();
	scavvie.beRepaired(10);
	
	return (0);
}