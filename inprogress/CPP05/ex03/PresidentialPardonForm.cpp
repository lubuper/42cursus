/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:16:34 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/28 17:40:03 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PPForm", 25, 5)
{
	this->target_ = "DESK";
	std::cout << "Presidential constructor." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PPForm", 25, 5), target_(target)
{
	std::cout << *this << "was made." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential destructor." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &base) : AForm("PPForm", 25, 5), target_(base.target_)
{
	std::cout << AForm::getName() << " Presidencial Pardon copy was made for " << this->getTarget() << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &base)
{
	if (this != &base)
	{
		this->target_ = base.getTarget();
		std::cout << AForm::getName() << " presidencial pardon copy was made from assignment for " << this->getTarget() << std::endl;
	}
	return (*this);
}

std::string	PresidentialPardonForm::getTarget() const
{
	return (this->target_);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getSignStatus() == false)
		throw(AForm::UnsignedException());
	else if (executor.getGrade() > this->getExecutionGrade())
		throw(AForm::GradeTooLowException());
	else
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
