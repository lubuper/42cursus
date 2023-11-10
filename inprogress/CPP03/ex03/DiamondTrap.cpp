/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:10:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/10 17:05:51 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "Default constructor" << std::endl;
	return ;
}
DiamondTrap::DiamondTrap(std::string name) : ClapTrap (name + "_clap_trap")
{
	this->_name = name;
	this->_damage = FragTrap::_damage;
	this->_energypoints = ScavTrap::_energypoints;
	this->_hitpoints = FragTrap::_hitpoints;
	std::cout << "DiamondTrap " << this->_name << " has crashed in!" << std::endl;
	return ;
}
DiamondTrap::DiamondTrap(DiamondTrap const &base) : ClapTrap(base.getName())
{
	this->_damage = FragTrap::_damage;
	this->_energypoints = ScavTrap::_energypoints;
	this->_hitpoints = FragTrap::_hitpoints;
	std::cout << "DiamondTrap copy constructor" << std::endl;
	return ;
}
DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &base)
{
	this->_damage = base.getDamagePoints();
	this->_energypoints = base.getEnergyPoints();
	this->_hitpoints = base.getHitPoints();
	return (*this);
}
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
	return ;
}
void	DiamondTrap::whoAmI()
{
	std::cout << "My name is " << this->_name << " and my ClapTrap name is ";
	std::cout << ClapTrap::getName() << "!"<< std::endl;
	return ;
}

void	DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
	return ;
}

void	DiamondTrap::sysCheck()
{
	std::cout << "DiamondTrap " << this->getName() << " has:" << std::endl;
	std::cout << this->getHitPoints() << " hitpoints" << std::endl;
	std::cout << this->getEnergyPoints() << " energy points" << std::endl;
	std::cout << "and he does " << this->getDamagePoints() << " points of damage" << std::endl;
}
