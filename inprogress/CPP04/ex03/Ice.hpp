/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:28:54 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/22 09:41:58 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class	Ice : public AMateria
{
private:
	std::string	type_;
public:
	Ice();
	Ice(const Ice &base);
	Ice &operator=(const Ice &base);
	~Ice();
	std::string const &getType() const;
	Ice *clone() const;
	void	use(ICharacter &target);
};

#endif