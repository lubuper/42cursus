/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:02:27 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/23 15:52:59 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("unknown"), grade_(150)
{
	std::cout << this->getName() << " has entered the building!" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : name_(name), grade_(grade)
{
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else
	{
		std::cout << "Bureaucrat " << this->getName() << " with a grade of ";
		std::cout << this->getGrade() << " has arrived!" << std::endl;
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << this->getName() << " has left the building!" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &base) : name_(base.name_), grade_(base.grade_)
{
	return ;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &base)
{
	if (this != &base)
	{
		this->grade_ = base.getGrade();
		std::cout << "assignment overload called" << std::endl;
	}
	return (*this);
}

std::string const	Bureaucrat::getName() const
{
	return (this->name_);
}

unsigned int 	Bureaucrat::getGrade() const
{
	return (this->grade_);
}

void	Bureaucrat::incrementGrade()
{
	if (this->grade_ > 1)
		this->grade_--;
	else
		throw(Bureaucrat::GradeTooHighException());
}

void	Bureaucrat::decrementGrade()
{
	if (this->grade_ < 150)
		this->grade_++;
	else
		throw(Bureaucrat::GradeTooLowException());
}

void	Bureaucrat::signForm(Form &some_form)
{
	try
	{
		some_form.beSigned(*this);
		std::cout << this->name_ << " \033[32msigned\033[0m " << some_form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->name_ << " \033[31mcouldn't sign\033[0m " << some_form.getName() << " because " << e.what() <<std::endl;
	}
}

std::ostream	&operator<<(std::ostream &COUT, Bureaucrat const &bureau)
{
	COUT << bureau.getName() << " , bureaucrat grade " << bureau.getGrade();
	return (COUT);
}
