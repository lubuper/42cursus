/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:55:31 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/26 15:30:38 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;
//memory address of the string variable
	std::cout << "&str = " << &str << std::endl;
//memory address held by stringPTR
	std::cout << "&stringPTR = " << &stringPTR << std::endl;
//memory address held by stringREF
	std::cout << "&stringREF = " << &stringREF << std::endl;
//value of string variable
	std::cout << "str = " << str << std::endl;
//value pointed to by stringPTR
	std::cout << "*stringPTR = " << *stringPTR << std::endl;
//value pointed to by stringREF
	std::cout << "stringREF = " << stringREF << std::endl;

}