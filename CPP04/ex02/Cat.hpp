/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:50:06 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/22 09:42:34 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Cat: public Animal
{
private:
	std::string	type;
	Brain	*brain_;
public:
	Cat();
	Cat(const Cat &base);
	Cat	&operator=(const Cat &base);
	~Cat();
	void	makeSound(void) const;
	std::string	getType(void) const;
};

#endif
