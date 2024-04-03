/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:14:03 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/23 15:46:29 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name_("default"), signed_(0), req_sign_grade_(150), req_execution_grade(150)
{
	std::cout << "Form constructor" << std::endl;
}

Form::Form(std::string name, unsigned int sign, unsigned int execute) : name_(name), \
	signed_(0), req_sign_grade_(sign), req_execution_grade(execute)
{
	if (sign > 150 || execute > 150)
		throw (Form::GradeTooLowException());
	else if (sign < 1 || execute < 1)
		throw (Form::GradeTooHighException());
	else
		std::cout << "A " << this->name_ << " form was made" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor" << std::endl;
}

Form::Form(Form const &base) : name_(base.getName()), signed_(0), \
	req_sign_grade_(base.getSignGrade()), req_execution_grade(base.getExecutionGrade()) 
{
	std::cout << this->getName() << " Form was copied from " << base.getName() << std::endl;
}

Form &Form::operator=(Form const &base)
{
	if (this->getName() != base.getName())
	{
		this->signed_ = base.getSignStatus();
	}
	return (*this);
}

std::string	Form::getName() const
{
	return (this->name_);
}

void	Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->getSignGrade())
		throw (Form::GradeTooLowException());
	else if (this->getSignStatus() == 1)
		throw(Form::AlreadySignedException());
	else
		this->signed_ = 1;
}

bool	Form::getSignStatus() const
{
	return(this->signed_);
}

unsigned int	Form::getSignGrade() const
{
	return(this->req_sign_grade_);
}

unsigned int	Form::getExecutionGrade() const
{
	return(this->req_execution_grade);
}

std::ostream	&operator<<(std::ostream &COUT, Form const &base)
{
	if (base.getSignStatus())
	{
		COUT << base.getName() << " Form with a " << "sign grade of " << base.getSignGrade() \
		<< " and an execution grade of " << base.getExecutionGrade() << " is SIGNED." << std::endl;
	}
	else
	{
		COUT << base.getName() << " Form with a " << "sign grade of " << base.getSignGrade() \
		<< " and an execution grade of " << base.getExecutionGrade() << " is NOT SIGNED." << std::endl;
	}
	return (COUT);
}