/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:14:03 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/23 16:45:37 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name_("default"), signed_(0), req_sign_grade_(150), req_execution_grade(150)
{
	std::cout << "AForm constructor" << std::endl;
}

AForm::AForm(std::string name, unsigned int sign, unsigned int execute) : name_(name), \
	signed_(0), req_sign_grade_(sign), req_execution_grade(execute)
{
	if (sign > 150 || execute > 150)
		throw (AForm::GradeTooLowException());
	else if (sign < 1 || execute < 1)
		throw (AForm::GradeTooHighException());
	else
		std::cout << "A " << this->name_ << " form was made" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm destructor" << std::endl;
}

AForm::AForm(AForm const &base) : name_(base.getName()), signed_(0), \
	req_sign_grade_(base.getSignGrade()), req_execution_grade(base.getExecutionGrade()) 
{
	std::cout << this->getName() << " AForm was copied from " << base.getName() << std::endl;
}

AForm &AForm::operator=(AForm const &base)
{
	if (this->getName() != base.getName())
	{
		this->signed_ = base.getSignStatus();
	}
	return (*this);
}

std::string	AForm::getName() const
{
	return (this->name_);
}

void	AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->getSignGrade())
		throw (AForm::GradeTooLowException());
	else if (this->getSignStatus() == 1)
		throw(AForm::AlreadySignedException());
	else
		this->signed_ = 1;
}

bool	AForm::getSignStatus() const
{
	return(this->signed_);
}

unsigned int	AForm::getSignGrade() const
{
	return(this->req_sign_grade_);
}

unsigned int	AForm::getExecutionGrade() const
{
	return(this->req_execution_grade);
}

std::ostream	&operator<<(std::ostream &COUT, AForm const &base)
{
	if (base.getSignStatus())
	{
		COUT << base.getName() << " form with a " << "sign grade of " << base.getSignGrade() \
		<< " and an execution grade of " << base.getExecutionGrade() << " is SIGNED." << std::endl;
	}
	else
	{
		COUT << base.getName() << " form with a " << "sign grade of " << base.getSignGrade() \
		<< " and an execution grade of " << base.getExecutionGrade() << " is NOT SIGNED." << std::endl;
	}
	return (COUT);
}