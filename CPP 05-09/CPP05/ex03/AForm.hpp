/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:14:11 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/28 17:56:04 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
private:
	std::string const	name_;
	bool	signed_;
	unsigned int const	req_sign_grade_;
	unsigned int const	req_execution_grade;	
public:
	AForm();
	AForm(std::string name, unsigned int sign, unsigned int execute);
	virtual ~AForm();
	AForm(AForm const &base);
	AForm &operator=(AForm const &base);
	virtual void	beSigned(Bureaucrat &b);
	std::string	getName() const;
	bool	getSignStatus() const;
	unsigned int	getSignGrade() const;
	unsigned int	getExecutionGrade() const;
	virtual void	execute(Bureaucrat const &executor) const = 0;

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
	class	UnsignedException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("the form has \033[34mNO signature\033[0m");
			}
	};
};

std::ostream	&operator<<(std::ostream &COUT, AForm const &base);

#endif