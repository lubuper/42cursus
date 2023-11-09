/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:54:29 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/08 12:16:55 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _damage(20), \
	_energypoints(50), _hitpoints(100)
{
	std::cout << "ClapTrap " << this->_name << " ONline" << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const &base)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_damage = base.getDamagePoints();
	this->_energypoints = base.getEnergyPoints();
	this->_hitpoints = base.getHitPoints();
	return ;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &base)
{
	
	this->_name = base.getName();
	this->_damage = base.getDamagePoints();
	this->_energypoints = base.getEnergyPoints();
	this->_hitpoints = base.getHitPoints();
	std::cout << "Operator assignment overload called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " OFFline" << std::endl;
	return ;
}

void	ClapTrap::attack(const  std::string& target)
{
	if (this->getHitPoints() > 0 && this->getEnergyPoints() > 0)
	{
		//CONNECT TARGET WITH A CLAPTRAP CLASS OBJECT
		this->setEnergyPoints(this->getEnergyPoints() - 1);
		std::cout << "ClapTrap " << this->getName() << " attacks " << target;
		std::cout << ", causing " << this->getDamagePoints() << " of damage!" << std::endl;
	}
	else if (this->getHitPoints() == 0 && this->getEnergyPoints() == 0)
		std::cout << "ClapTrap" << this->getName() << "has no hitpoints and no energy!" << std::endl;
	else if (this->getHitPoints() == 0)
		std::cout << "ClapTrap" << this->getName() << "has no hitpoints!" << std::endl;
	else if (this->getEnergyPoints() == 0)
		std::cout << "ClapTrap" << this->getName() << "has no energy!" << std::endl;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHitPoints() > 0)
	{
		int	temp = this->getHitPoints() - amount;
		if (temp <= 0)
			this->setHitPoints(0);
		else
			this->setHitPoints((unsigned int)temp);			
		std::cout << "ClapTrap " << this->getName() << " took " << amount << " of damage!";
		std::cout << " He has " << this->getHitPoints() << " Hit points left." << std::endl;
	}
	else
		std::cout << "ClapTrap" << this->getName() << "has already 0 hitpoints!" << std::endl;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getHitPoints() > 0 && this->getEnergyPoints() > 0 && this->getHitPoints() < 10)
	{
		this->setEnergyPoints(this->getEnergyPoints() - amount);
		this->setHitPoints(this->getHitPoints() + amount);
		std::cout << "ClapTrap " << this->getName();
		std::cout << " repaired himself! He is now " << this->getHitPoints();
		std::cout << " hitpoints!" << std::endl;
	}
	else if (this->getHitPoints() == 10)
		std::cout << "ClapTrap " << this->getName() << " already has max hitpoints!" << std::endl;
	else if (this->getHitPoints() == 0 && this->getEnergyPoints() == 0)
		std::cout << "ClapTrap " << this->getName() << " has no hitpoints and no energy!" << std::endl;
	else if (this->getHitPoints() == 0)
		std::cout << "ClapTrap " << this->getName() << " has no hitpoints!" << std::endl;
	else if (this->getEnergyPoints() == 0)
		std::cout << "ClapTrap " << this->getName() << " has no energy!" << std::endl;
	return ;
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return(this->_hitpoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return(this->_energypoints);
}

unsigned int	ClapTrap::getDamagePoints(void) const
{
	return(this->_damage);
}

std::string		ClapTrap::getName(void) const
{
	return(this->_name);
}

void	ClapTrap::setHitPoints(unsigned int hitpoints)
{
	this->_hitpoints = hitpoints;
	return ;
}

void	ClapTrap::setEnergyPoints(unsigned int energy)
{
	this->_energypoints = energy;
	return ;
}

void	ClapTrap::setDamagePoints(unsigned int damage)
{
	this->_damage = damage;
	return ;
}

void	ClapTrap::setName(std::string name)
{
	this->_name = name;
	return ;
}
