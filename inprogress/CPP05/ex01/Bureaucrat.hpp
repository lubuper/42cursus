/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:02:36 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/20 19:33:04 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <istream>
# include <iostream>

class	Bureaucrat
{
private:
	std::string const	name_;
	unsigned int	grade_;
public:
	Bureaucrat(); //OCF
	~Bureaucrat(); //OCF
	Bureaucrat(Bureaucrat const &base); //OCF
	Bureaucrat	&operator=(Bureaucrat const &base); //OCF

	Bureaucrat(std::string name, unsigned int grade); //name and grade constructor
	std::string const	getName() const; //getter
	unsigned int 		getGrade() const; //getter
	void	incrementGrade();
	void	decrementGrade();
	class	GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Exception: The grade which you're trying to pass cannot be < 1\n");
			}
	};
	class	GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Exception: The grade which you're trying to pass cannot be > 150\n");
			}
	};
	void	signForm();
};

std::ostream	&operator<<(std::ostream &COUT, Bureaucrat const &bureau);

#endif