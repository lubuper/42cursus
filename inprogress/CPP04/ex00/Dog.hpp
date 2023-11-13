/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:49:54 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/13 19:34:23 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class	Dog: public Animal
{
private:
	std::string type;
public:
	Dog();
	Dog(const Dog &base);
	Dog	&operator=(const Dog &base);
	~Dog();
	std::string	getType(void) const;
	void	makeSound(void) const;
};

#endif