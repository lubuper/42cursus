/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:59:04 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/28 16:45:09 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class	Bureaucrat;

class	ShrubberyCreationForm : public AForm
{
private:
	std::string	target_;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const &base);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &base);
	std::string	getTarget() const;
	void	execute(Bureaucrat const &executor) const;
};



#endif
