/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:40:38 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/30 12:30:48 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{	
}

ScalarConverter::ScalarConverter(ScalarConverter const &base)
{
	(void)base;
}
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &base)
{
	if (this != &base)
	{
		return (*this);
	}
	return (*this);
}

void	ScalarConverter::convert(std::string const input)
{
	
}