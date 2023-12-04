/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:40:38 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/04 18:29:20 by lde-sous         ###   ########.fr       */
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

void	fromChar(std::string const input)
{
	if (input[1])
	{
		std::cout << "Invalid: A char input cannot be a string" << std::endl;
		return ;
	}
	else if (input[0] < 48 || input[0] > 57)
	{
		std::cout << "char: '" << input[0] << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(input[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(input[0]) << ".0" << std::endl;
	}
}

int	findError(std::string const input)
{
	size_t	minus_pos = input.find('-');
	size_t	dot_pos = input.find('.');
	size_t	f_pos = input.find('f');

	if (minus_pos != std::string::npos && (minus_pos != 0 || input.find('-', minus_pos + 1) != std::string::npos))
	{
		std::cout << "Invalid: minus '-' sign" << std::endl;
		return (1);
	}
	if (dot_pos != std::string::npos && input.find('.', dot_pos + 1) != std::string::npos)
	{
		std::cout << "Invalid: dot '.' sign" << std::endl;
		return (1);
	}	
	if (f_pos != std::string::npos && input.size() - 1 != f_pos)
	{
		std::cout << "Invalid: 'f' in float notation" << std::endl;
		return (1);
	}
	for (int i = 0; input[i]; i++)
	{
		if ((input[i] < 48 && input[i] != 45 && input[i] != 46) || (input[i] > 57  && input[i] != 102))
		{
			std::cout << "Invalid: numeric and char mixed input" << std::endl;
			return (1);
		}
	}
	return (0);
}

void	fromInt(std::string const input)
{
	if (findError(input) == 1)
		return ;
	long result = atol(input.c_str());
	if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
	{
		std::cout << "Invalid : the input has an out of bounds type" << std::endl;
		return ;
	}
	if ((result >= 0 && result < 32) || result == 127)
		std::cout << "char: Non displayable" << std::endl;
	else if (result < 0 || result > 127)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(result) << "'" << std::endl;
	std::cout << "int: " << result << std::endl;
	std::cout << "float: " << static_cast<float>(result) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(result) << ".0" << std::endl;
}

void	fromDouble(std::string const input)
{
	if (findError(input) == 1)
		return ;
	char *endpointer;
	double result = strtod(input.c_str(), &endpointer);
	if (result > std::numeric_limits<double>::max() || result < -std::numeric_limits<double>::max())
	{
		std::cout << "Invalid : the input has an out of bounds type" << std::endl;
		return ;
	}
	if ((result >= 0 && result < 32) || result == 127 || static_cast<int>(result) != result)
		std::cout << "char: Non displayable" << std::endl;
	else if (result < 0 || result > 127)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(result) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(result) << std::endl;
	std::cout << "float: " << static_cast<float>(result) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(result) << std::endl;
}

void	fromFloat(std::string const input)
{
	if (findError(input) == 1)
		return ;
	char *endpointer;
	double result = strtof(input.c_str(), &endpointer);
	if (result > std::numeric_limits<float>::max() || result < -std::numeric_limits<float>::max())
	{
		std::cout << "Invalid : the input has an out of bounds type" << std::endl;
		return ;
	}
	if ((result >= 0 && result < 32) || result == 127 || static_cast<int>(result) != result)
		std::cout << "char: Non displayable" << std::endl;
	else if (result < 0 || result > 127)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(result) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(result) << std::endl;
	std::cout << "float: " << static_cast<float>(result) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(result) << std::endl;
}

void	ScalarConverter::convert(std::string const input)
{
	if (isdigit(input[0]) || (input[0] == 45 && input.size() > 1))
	{
		if (input.find('.') != std::string::npos)
		{
			if (input[input.size() - 1] == 'f')
				return (fromFloat(input));
			else
				return (fromDouble(input));
		}
		else
			return (fromInt(input));
	}
	else
		return (fromChar(input));
}