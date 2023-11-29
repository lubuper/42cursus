/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:02:19 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/29 17:52:35 by lde-sous         ###   ########.fr       */
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
	std::cout << "\033[32m---------------------------\033[0m" << std::endl;
	return (0);
}

/* int	main(void)
{
	std::srand(std::time(0)); // common practice to seed the pseudo-random number generator

	// Constructors
	std::cout << std::endl;
	std::cout << "CONSTRUCTING:" << std::endl;
	std::cout << "----------------------------" << std::endl;

	Bureaucrat				bob("Bob", 1);
	Bureaucrat				bill("Bill", 142);
	ShrubberyCreationForm	shrub("shrub");
	RobotomyRequestForm		robo("robo");
	PresidentialPardonForm	president("president");
	std::cout << std::endl << std::endl;
	//-----------------------------------------------------


	// Executing
	// ShrubberyCreationForm : sign 145, exec 137
	// RobotomyRequestForm sign 72, exec 45
	// PresidentialPardonForm sign 25, exec 5

	std::cout << "SHRUBBERY CREATION FORM:" << std::endl;
	std::cout << "----------------------------" << std::endl;


	std::cout << std::endl << "[UNSIGNED]" << std::endl;
	bob.executeForm(shrub);
	shrub.beSigned(bob);


	std::cout << std::endl << "[SIGNED]" << std::endl;
	bob.executeForm(shrub);
	std::cout << std::endl;


	std::cout << std::endl << "[GRADE TO EXE TOO LOW]" << std::endl;
	bill.executeForm(shrub);
	std::cout << std::endl << std::endl;
	//-----------------------------------------------------


	std::cout << std::endl;
	std::cout << "ROBOTOMY REQUEST FORM:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << std::endl << "[UNSIGNED]" << std::endl;
	bob.executeForm(robo);
	robo.beSigned(bob);


	std::cout << std::endl << "[SIGNED (50% failure chance)]" << std::endl;
	bob.executeForm(robo);
	bob.executeForm(robo);
	bob.executeForm(robo);
	bob.executeForm(robo);
	bob.executeForm(robo);
	std::cout << std::endl;


	std::cout << std::endl << "[GRADE TO EXE TOO LOW]" << std::endl;
	bill.executeForm(robo);
	std::cout << std::endl << std::endl;
	//-----------------------------------------------------


	std::cout << std::endl;
	std::cout << "PRESIDENTIAL PARDON FORM:" << std::endl;
	std::cout << "----------------------------" << std::endl;


	std::cout << std::endl << "[UNSIGNED]" << std::endl;
	bob.executeForm(president);
	president.beSigned(bob);


	std::cout << std::endl << "[SIGNED]" << std::endl;
	bob.executeForm(president);
	std::cout << std::endl;


	std::cout << std::endl << "[GRADE TO EXE TOO LOW]" << std::endl;
	bill.executeForm(president);
	std::cout << std::endl << std::endl;
	//-----------------------------------------------------


	std::cout << std::endl;
	std::cout << "DESTRUCTORS:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	return (0);
	//-------------------------------------------------------
} */