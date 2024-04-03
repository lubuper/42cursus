/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:45:17 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/14 10:50:45 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{
protected:
	std::string	type;
public:
	WrongCat();
	WrongCat(const WrongCat &base);
	WrongCat	&operator=(const WrongCat &base);
	~WrongCat();
	std::string	getType(void) const;
	void	makeSound(void) const;
	
};

#endif