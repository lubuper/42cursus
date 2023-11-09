/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:55:50 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/08 22:05:48 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
/* 	ClapTrap	clappy("clappy"); */
	ScavTrap	scavvie("scavvie");
	FragTrap	fraggy("fraggy");
	
/* 	clappy.attack("trash bin");
	clappy.takeDamage(2);
	clappy.beRepaired(1); */

	scavvie.sysCheck();
	scavvie.attack("car");
	scavvie.takeDamage(10);
	scavvie.sysCheck();
	scavvie.guardGate();

	fraggy.highFivesGuys();
	fraggy.attack("random pedestrian");
	fraggy.highFivesGuys();
	fraggy.takeDamage(30);
	
	return (0);
}