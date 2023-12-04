/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:02:19 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/29 19:54:55 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	/* std::cout << std::endl;
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
		b2.executeForm(pp);
		std::cout << std::endl;
		b1.executeForm(chance);
		b2.executeForm(chance);
		std::cout << std::endl;
		b1.executeForm(tree);
		b2.executeForm(tree);
		std::cout << "\033[31m---------------------------\033[0m" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\033[32m---------------------------\033[0m" << std::endl; */
	Intern	someone;
	Bureaucrat	b1("Ginger", 3);
	Bureaucrat	b2("Travis", 65);
	AForm	*firstform;
	AForm	*secondform;
	AForm	*thirdform;
	firstform = someone.makeForm("PPForm", "Costa");
	std::cout << "\033[32m---------------------------\033[0m" << std::endl;
	secondform = someone.makeForm("PPForm", "Mr.Pizza");
	std::cout << "\033[32m---------------------------\033[0m" << std::endl;
	thirdform = someone.makeForm("RobReq", "Trash Bin");
	std::cout << "\033[32m---------------------------\033[0m" << std::endl;
	b1.signForm(*firstform);
	b2.signForm(*secondform);
	b1.signForm(*thirdform);
	b1.executeForm(*firstform);
	b1.executeForm(*secondform);
	b1.executeForm(*thirdform);
	delete firstform;
	delete secondform;
	delete thirdform;
	return (0);
}
