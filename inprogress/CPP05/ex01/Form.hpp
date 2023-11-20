/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:14:11 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/20 19:40:40 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form
{
private:
	std::string const	name_;
	bool	signed_;
	unsigned int const	req_sign_grade_;
	unsigned int const	req_execution_grade;	
public:
	Form();
	~Form();
	Form(Form const &base);
	Form &operator=(Form const &base);
	void	beSigned(Bureaucrat b);
	std::string	getName() const;
};

#endif