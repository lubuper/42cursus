/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:16:15 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/27 10:29:58 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("PPForm", 145, 137)
{
	this->target_ = "DESK";
	std::cout << "Presidential Pardon constructor." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("PPForm", 145, 137), target_(target)
{
	std::cout << *this << "was made." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Presidential Pardon destructor." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &base)
{
	
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &base)
{
	
}

std::string	ShrubberyCreationForm::getTarget() const
{
	
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	
}
