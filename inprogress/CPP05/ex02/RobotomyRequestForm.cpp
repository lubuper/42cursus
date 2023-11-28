/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:16:27 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/28 17:40:25 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("PPForm", 72, 45)
{
	this->target_ = "DESK";
	std::cout << "Robotomy constructor." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("PPForm", 72, 45), target_(target)
{
	std::cout << *this << "was made." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy destructor." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &base) : AForm("PPForm", 72, 45), target_(base.target_)
{
	std::cout << AForm::getName() << " robotomy copy was made for " << this->getTarget() << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &base)
{
	if (this != &base)
	{
		this->target_ = base.getTarget();
		std::cout << AForm::getName() << " robotomy copy was made from assignment for " << this->getTarget() << std::endl;
	}
	return (*this);
}

std::string	RobotomyRequestForm::getTarget() const
{
	return (this->target_);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
 	std::time_t rNum = std::time(0);
	
	std::cout << "PrrrRhrhrrrRrRhRRrrrr" << std::endl;
	std::cout << "VhzzhzZzzzZhzzzzzzzh" << std::endl;
	std::cout << "Zhhhhhhhhhhzhzhzh" << std::endl;
	std::cout << "BbbbZZZZZZZZZZZZZZZzzz" << std::endl;
	if (rNum % 2 == 0)
	{
		std::cout << executor.getName() << ", you have been robotomized successfuly!" << std::endl;
	}
	else
	{
		std::cout << executor.getName() << ", I'm sorry to inform you that your robotomization has failed" << std::endl;
	}
	
}
