/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:02:19 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/28 17:57:17 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardon.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	std::cout << std::endl;
	Bureaucrat	b1("Boyle", 3);
	Bureaucrat	b2("Travis", 149);
	PresidentialPardon	pp("Batatinha");

	std::cout << "\033[32m---------------------------\033[0m" << std::endl;
	try
	{
 		b2.signForm(pp);
		b1.signForm(pp);
		b2.signForm(pp);
		b1.signForm(pp);
		b1.signForm(pp);
		b1.executeForm(pp);
		b2.executeForm(pp);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\033[32m---------------------------\033[0m" << std::endl;
	return (0);
}