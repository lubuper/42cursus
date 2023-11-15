/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:28:54 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/15 18:24:18 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class	Cure : public AMateria
{
private:
	std::string	_type;
public:
	Cure();
	Cure(const Cure &base);
	Cure &operator=(const Cure &base);
	~Cure();
	std::string const &getType() const;
	Cure *clone() const;
	void	use(ICharacter &target);
};

#endif