/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:14:03 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/20 19:45:19 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name_("default"), signed_(false), req_sign_grade_(150), req_execution_grade(150)
{
	std::cout << "Form constructor" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor" << std::endl;
}

Form::Form(Form const &base)
{
	
}

Form &Form::operator=(Form const &base)
{
	
}

std::string	Form::getName() const
{
	return (this->name_);
}

void	Form::beSigned(Bureaucrat b)
{
	
}
