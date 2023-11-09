/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:56:22 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/08 12:10:49 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>
# include <istream>

class	ClapTrap
{
protected:
	std::string		_name;
	unsigned int	_damage;
	unsigned int	_energypoints;
	unsigned int	_hitpoints;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const &base);
	ClapTrap &operator=(const ClapTrap &base);
	~ClapTrap();
	void	attack(const  std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	unsigned int	getHitPoints(void) const;
	unsigned int	getEnergyPoints(void) const;
	unsigned int	getDamagePoints(void) const;
	std::string		getName(void) const;
	void	setHitPoints(unsigned int hitpoints);
	void	setEnergyPoints(unsigned int energy);
	void	setDamagePoints(unsigned int damage);
	void	setName(std::string name);
	
};

#endif