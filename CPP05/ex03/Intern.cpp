/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:16:49 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/30 10:28:41 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "An intern has been summoned" << std::endl;
}

Intern::~Intern()
{
	std::cout << "An intern has been discharged" << std::endl;
}

Intern::Intern(const Intern &base)
{
	std::cout << "An intern has been cloned" << std::endl;
	*this = base;
}

Intern &Intern::operator=(const Intern &base)
{
	(void)base;
	std::cout << "An intern has been assigned" << std::endl;
	return (*this);
}

AForm	*Intern::PPForm(std::string target)
{
	return new PresidentialPardonForm(target);
}
AForm	*Intern::RobReq(std::string target)
{
	return new RobotomyRequestForm(target);
}
AForm	*Intern::Shrubb(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm	*Intern::makeForm(std::string form_name, std::string target)
{
	try
	{
		AForm* (Intern::*possible_forms[3])(std::string) = {&Intern::PPForm, &Intern::RobReq, &Intern::Shrubb};
		std::string possible_names[3] = {"PPForm", "RobReq", "Shrubb"};
		int		rightone = -1;

		for (int i = 0; i < 3; i++)
			if (form_name == possible_names[i])
				rightone = i;
		if (rightone != -1)
			return(this->*possible_forms[rightone])(target);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}