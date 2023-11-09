/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:24:25 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/08 21:58:53 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name): ClapTrap (name)
{
	std::cout << "FragTrap " << this->_name << " has arrived!" << std::endl;
	return ;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &base) : ClapTrap(base.getName())
{
	this->_damage = base.getDamagePoints();
	this->_energypoints = base.getEnergyPoints();
	this->_hitpoints = base.getHitPoints();
	std::cout << "FragTrap copy constructor called" << std::endl;
	return ;
}

FragTrap	&FragTrap::operator=(FragTrap const &base)
{
	this->_damage = base.getDamagePoints();
	this->_energypoints = base.getEnergyPoints();
	this->_hitpoints = base.getHitPoints();
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->getName() << " is waiting to HighFive someone!"<< std::endl;
	return ;
}

void	FragTrap::attack(const std::string &target)
{
	if (this->getHitPoints() > 0 && this->getEnergyPoints() > 0)
	{
		//CONNECT TARGET WITH A FRAGTRAP CLASS OBJECT
		this->setEnergyPoints(this->getEnergyPoints() - 1);
		std::cout << "FragTrap " << this->getName() << " attacks " << target;
		std::cout << ", causing " << this->getDamagePoints() << " of damage!" << std::endl;
	}
	else if (this->getHitPoints() == 0 && this->getEnergyPoints() == 0)
		std::cout << "FragTrap " << this->getName() << " has no hitpoints and no energy!" << std::endl;
	else if (this->getHitPoints() == 0)
		std::cout << "FragTrap " << this->getName() << " has no hitpoints!" << std::endl;
	else if (this->getEnergyPoints() == 0)
		std::cout << "FragTrap " << this->getName() << " has no energy!" << std::endl;
	return ;
}
