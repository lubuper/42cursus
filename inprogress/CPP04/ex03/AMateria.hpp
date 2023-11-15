/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:55:12 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/15 19:34:50 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <istream>
# include <iostream>
# include "ICharacter.hpp"

class	AMateria
{
protected:
	const std::string	_type;
public:
	AMateria();
	AMateria(const AMateria &base);
	~AMateria();
	AMateria(std::string const &type);
	std::string const &getType() const;
	virtual AMateria *clone() const = 0;
	virtual void	use(ICharacter &target);
};

#endif