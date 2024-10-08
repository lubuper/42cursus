/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:55:12 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/28 14:19:21 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <istream>
# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class	AMateria
{
protected:
	std::string	type_;
public:
	AMateria();
	AMateria(const AMateria &base);
	virtual ~AMateria();
	virtual AMateria &operator=(const AMateria &base);
	AMateria(std::string const &type);
	virtual std::string const &getType() const;
	virtual AMateria *clone() const = 0;
	virtual void	use(ICharacter &target);
};

#endif
