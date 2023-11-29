/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:16:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/29 20:11:48 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	Intern();
	~Intern();
	Intern(const Intern &base);
	Intern &operator=(const Intern &base);
	AForm	*makeForm(std::string form_name, std::string target);
	AForm	*PPForm(std::string target);
	AForm	*RobReq(std::string target);
	AForm	*Shrubb(std::string target);
	class	NonExistingNameException
	{
		public:
			virtual const char	*what() const throw()
			{
				return ("That form's name is nonexistent\n");
			}
	};
};

#endif