/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:02:19 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/04 18:44:48 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	std::cout << std::endl;
	try
	{
		std::cout << "\033[32m----------TRYING TO CREATE BUREAUCRATS-----------------\033[0m" << std::endl;
		Bureaucrat	b1("Ginger", 3);
		Bureaucrat	b2("Travis", 149);
		//Bureaucrat	btest("Gary", 250);
		//Bureaucrat	btest2("Heather", 0);	
		std::cout << std::endl;
		std::cout << "\033[32m----------TRYING TO CREATE FORMS-----------------\033[0m" << std::endl;
		PresidentialPardonForm	pp("Batatinha");
		ShrubberyCreationForm	tree("HOME");
		RobotomyRequestForm	chance("Mr.Robot");
		//AForm	test;
		std::cout << std::endl;
		std::cout << "\033[32m----------TRYING TO SIGN FORMS-----------------\033[0m" << std::endl;
		b2.signForm(pp);
		b1.signForm(pp);
		b2.signForm(pp);
		b1.signForm(pp);
		std::cout << std::endl;
		b2.signForm(chance);
		b1.signForm(chance);
		b2.signForm(chance);
		b1.signForm(chance);
		std::cout << std::endl;
		b2.signForm(tree);
		b1.signForm(tree);
		b2.signForm(tree);
		b1.signForm(tree);
		std::cout << std::endl;
		std::cout << "\033[32m----------TRYING TO EXECUTE FORMS-----------------\033[0m" << std::endl;
		b1.executeForm(pp);
		std::cout << "\033[32mTravis' turn:\033[0m" << std::endl;
		b2.executeForm(pp);
		std::cout << std::endl;
		b1.executeForm(chance);
		std::cout << "\033[32mTravis' turn:\033[0m" << std::endl;
		b2.executeForm(chance);
		std::cout << std::endl;
		b1.executeForm(tree);
		std::cout << "\033[32mTravis' turn:\033[0m" << std::endl;
		b2.executeForm(tree);
		std::cout << "\033[31m---------------------------\033[0m" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\033[32m---------------------------\033[0m" << std::endl;
	return (0);
}
