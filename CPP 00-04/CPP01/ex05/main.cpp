/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:28:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/02 18:42:30 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	harl2;

	std::cout << "Debug: " << std::endl;
	harl2.complain("debug");
	std::cout << "Info: " << std::endl;
	harl2.complain("info");
	std::cout << "Warning: " << std::endl;
	harl2.complain("warning");
	std::cout << "Error: " << std::endl;
	harl2.complain("error");
	return (0);
}
