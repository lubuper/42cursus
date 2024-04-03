/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:38:19 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/16 15:14:03 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	this->_damage = 20;
	this->_energypoints = 50;
	this->_hitpoints = 100;
	std::cout << "ScavTrap default constructor" << std::endl;
	return ;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap (name)
{
	this->_damage = 20;
	this->_energypoints = 50;
	this->_hitpoints = 100;
	std::cout << "ScavTrap " << this->_name << " ONline" << std::endl;
	return ;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor" << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const &base) : ClapTrap(base.getName())
{
	this->_damage = 20;
	this->_energypoints = 50;
	this->_hitpoints = 100;
	std::cout << "ScavTrap copy constructor" << std::endl;
	return ;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &base)
{
	this->_damage = base.getDamagePoints();
	this->_energypoints = base.getEnergyPoints();
	this->_hitpoints = base.getHitPoints();
	return (*this);
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->getName() << " has entered Gate Keeper mode." << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->getHitPoints() > 0 && this->getEnergyPoints() > 0)
	{
		//CONNECT TARGET WITH A SCAVTRAP CLASS OBJECT
		this->setEnergyPoints(this->getEnergyPoints() - 1);
		std::cout << "ScavTrap " << this->getName() << " attacks " << target;
		std::cout << ", causing " << this->getDamagePoints() << " of damage!" << std::endl;
	}
	else if (this->getHitPoints() == 0 && this->getEnergyPoints() == 0)
		std::cout << "ScavTrap " << this->getName() << " has no hitpoints and no energy!" << std::endl;
	else if (this->getHitPoints() == 0)
		std::cout << "ScavTrap " << this->getName() << " has no hitpoints!" << std::endl;
	else if (this->getEnergyPoints() == 0)
		std::cout << "ScavTrap " << this->getName() << " has no energy!" << std::endl;
	return ;
}

void	ScavTrap::sysCheck()
{
	std::cout << "ScavTrap " << this->getName() << " has:" << std::endl;
	std::cout << this->getHitPoints() << " hitpoints" << std::endl;
	std::cout << this->getEnergyPoints() << " energy points" << std::endl;
	std::cout << "and he does " << this->getDamagePoints() << " points of damage" << std::endl;
}
