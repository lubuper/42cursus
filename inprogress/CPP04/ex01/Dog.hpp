/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:49:54 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/14 11:15:19 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Dog: public Animal
{
private:
	std::string type;
	Brain	*_brain;
public:
	Dog();
	Dog(const Dog &base);
	Dog	&operator=(const Dog &base);
	~Dog();
	std::string	getType(void) const;
	void	makeSound(void) const;
};

#endif