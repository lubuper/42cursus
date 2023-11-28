/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardon.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:16:34 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/28 17:40:03 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardon.hpp"

PresidentialPardon::PresidentialPardon() : AForm("PPForm", 25, 5)
{
	this->target_ = "DESK";
	std::cout << "Presidential constructor." << std::endl;
}

PresidentialPardon::PresidentialPardon(std::string target) : AForm("PPForm", 25, 5), target_(target)
{
	std::cout << *this << "was made." << std::endl;
}

PresidentialPardon::~PresidentialPardon()
{
	std::cout << "Presidential destructor." << std::endl;
}

PresidentialPardon::PresidentialPardon(PresidentialPardon const &base) : AForm("PPForm", 25, 5), target_(base.target_)
{
	std::cout << AForm::getName() << " Presidencial Pardon copy was made for " << this->getTarget() << std::endl;
}

PresidentialPardon &PresidentialPardon::operator=(PresidentialPardon const &base)
{
	if (this != &base)
	{
		this->target_ = base.getTarget();
		std::cout << AForm::getName() << " presidencial pardon copy was made from assignment for " << this->getTarget() << std::endl;
	}
	return (*this);
}

std::string	PresidentialPardon::getTarget() const
{
	return (this->target_);
}

void	PresidentialPardon::execute(Bureaucrat const &executor) const
{
	std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
