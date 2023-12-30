/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:53:11 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/29 21:34:50 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{	
}

RPN::~RPN()
{	
}

RPN::RPN(RPN const &base)
{
	*this = base;	
}

RPN	&RPN::operator=(RPN const &base)
{
	if (this != &base)
		arr_ = base.arr_;
	return (*this);
}

void	RPN::fillstack(std::string parameters)
{
	std::string	operators = "+-*/";
	std::string temp;
	const char	*params = parameters.c_str();
	for (size_t i = 0; i < parameters.length(); i++)
	{
		if (params[i] == ' ')
			continue;
		else if (isdigit(params[i]))
		{
			temp = params[i];
			arr_.push(std::atof(temp.c_str()));
		}
		else if (operators.find(params[i]) != std::string::npos)
			arr_.push(executeRPN(params[i]));
		 else
			throw (std::runtime_error("Error: invalid parameter"));
	}
	std::cout << arr_.top() << std::endl;
	arr_.pop();
}

double	RPN::executeRPN(char m_operator)
{
	double last_operand;
	double first_operand;
	
	if (arr_.empty())
		throw (std::runtime_error("Error: not enough operands to execute"));
	last_operand = arr_.top();
	arr_.pop();
	if (arr_.empty())
		throw (std::runtime_error("Error: not enough operands to execute"));
	first_operand = arr_.top();
	arr_.pop();
	switch(m_operator)
	{
		case '+':
			return (first_operand + last_operand);
		case '-':
			return (first_operand - last_operand);
		case '*':
			return (first_operand * last_operand);
		case '/':
			return (first_operand / last_operand);
		default:
			throw (std::runtime_error("Error: couldn't perform the operation"));
	}
}
