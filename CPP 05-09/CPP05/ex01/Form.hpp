/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:14:11 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/23 15:58:21 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
private:
	std::string const	name_;
	bool	signed_;
	unsigned int const	req_sign_grade_;
	unsigned int const	req_execution_grade;	
public:
	Form();
	Form(std::string name, unsigned int sign, unsigned int execute);
	~Form();
	Form(Form const &base);
	Form &operator=(Form const &base);
	void	beSigned(Bureaucrat &b);
	std::string	getName() const;
	bool	getSignStatus() const;
	unsigned int	getSignGrade() const;
	unsigned int	getExecutionGrade() const;

	class	GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("it is required a \033[31mlower\033[0m grade");
			}
	};
	class	GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("it is required a \033[31mhigher\033[0m grade");
			}
	};
	class	AlreadySignedException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("the form is \033[34malready signed\033[0m");
			}
	};
};

std::ostream	&operator<<(std::ostream &COUT, Form const &base);

#endif