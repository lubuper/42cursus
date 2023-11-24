/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:24:31 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/13 19:39:01 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>
# include <istream>

class	Animal
{
protected:
	std::string	type;
public:
	Animal();
	Animal(const Animal &base);
	Animal	&operator=(const Animal &base);
	virtual ~Animal();
	virtual std::string	getType(void) const;
	virtual void	makeSound(void) const;
};

#endif