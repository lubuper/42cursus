/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:16:27 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/29 17:49:09 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobReq", 72, 45)
{
	this->target_ = "DESK";
	std::cout << "Robotomy constructor." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobReq", 72, 45), target_(target)
{
	std::cout << *this << "was made." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy destructor." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &base) : AForm("RobReq", 72, 45), target_(base.target_)
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
 	if (this->getSignStatus() == false)
		throw(AForm::UnsignedException());
	else if (executor.getGrade() > this->getExecutionGrade())
		throw(AForm::GradeTooLowException());
	else
	{
		std::time_t rNum = std::time(0);
		std::cout << "\033[9mPrrrRhrhrrrRrRhRRrrrr" << std::endl;
		std::cout << "VhzzhzZzzzZhzzzzzzzh" << std::endl;
		std::cout << "Zhhhhhhhhhhzhzhzh" << std::endl;
		std::cout << "BbbbZZZZZZZZZZZZZZZzzz\033[0m" << std::endl;
		if (rNum % 2 == 0)
			std::cout << this->getTarget() << ", you have been robotomized successfuly!" << std::endl;
		else
			std::cout << this->getTarget() << ", I'm sorry to inform you that your robotomization has failed" << std::endl;
	}
}
