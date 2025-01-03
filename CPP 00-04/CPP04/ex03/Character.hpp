/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:47:16 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/24 14:59:34 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class	Character : public ICharacter
{
private:
	AMateria*	inventory[4];
	std::string const	name_;
public:
	Character();
	Character(std::string name);
	~Character();
	Character(Character const &base);
	Character &operator=(Character const &base);
	std::string const	&getName() const;
	void	equip(AMateria* m);
	void	unequip(int idx);
	void	use(int idx, ICharacter& target);
	AMateria	*getInventoryMateria(int idx);
};

#endif