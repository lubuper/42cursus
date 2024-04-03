/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:02:19 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/23 16:01:00 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int	main(void)
{
	std::cout << std::endl;
	Bureaucrat	b1("Boyle", 3);
	Bureaucrat	b2("Travis", 149);
/* 	Bureaucrat	b3("IMPOSTOR", 0);
	Form	f3("f3-INVALID", 160, 2); */

	Form	f1("f1-130G1E", 130, 1);
	Form	f2("f2-2G149E", 2, 149);
	std::cout << "\033[32m---------------------------\033[0m" << std::endl;
	try
	{
		b2.signForm(f1);
		b1.signForm(f1);
		b2.signForm(f2);
		b1.signForm(f2);
		b1.signForm(f1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\033[32m---------------------------\033[0m" << std::endl;
	return (0);
}