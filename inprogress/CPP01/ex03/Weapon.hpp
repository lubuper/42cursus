/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:41:50 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/26 19:02:01 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <istream>
# include <iostream>

class	Weapon
{
private:
	std::string	type;
public:
	Weapon(std::string wtype);
	~Weapon();
	const std::string&	getType();
	void	setType(std::string wtype);
};
#endif