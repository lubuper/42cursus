/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:49:54 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/22 09:42:34 by lde-sous         ###   ########.fr       */
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
	Brain	*brain_;
public:
	Dog();
	Dog(const Dog &base);
	Dog	&operator=(const Dog &base);
	~Dog();
	std::string	getType(void) const;
	void	makeSound(void) const;
};

#endif