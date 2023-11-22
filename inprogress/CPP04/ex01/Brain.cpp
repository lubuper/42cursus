/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:09:46 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/22 09:41:19 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "\033[38;5;200mBrainzzz\033[0m" << std::endl;
}

Brain::~Brain()
{
	std::cout << "\033[38;5;200mno more brainz!\033[0m" << std::endl;
}

Brain::Brain(const Brain &base)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = base.ideas[i];
	std::cout << "\033[38;5;200mcopy of Brainzzz\033[0m" << std::endl;
	
}

Brain &Brain::operator=(const Brain &base)
{
	if (this != &base)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = base.ideas[i];
		std::cout << "\033[38;5;200manother copy of Brainzzz\033[0m" << std::endl;
	}
	return (*this);
}
