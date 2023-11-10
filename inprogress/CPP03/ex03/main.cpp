/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:55:50 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/10 16:56:29 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	std::cout << std::endl;
	ClapTrap	clappy("clappy");
	ScavTrap	scavvie("scavvie");
	FragTrap	fraggy("fraggy");
	DiamondTrap	didi("didi");

	std::cout << "clappy name is " << clappy.getName() << std::endl;
	std::cout << std::endl;
	
	scavvie.sysCheck();
	std::cout << std::endl;
	
	fraggy.sysCheck();
	std::cout << std::endl;
	
	didi.sysCheck();
	didi.whoAmI();
	
	return (0);
}