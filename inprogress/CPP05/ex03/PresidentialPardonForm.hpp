/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:58:46 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/28 16:45:20 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class	Bureaucrat;

class	PresidentialPardonForm : public AForm
{
private:
	std::string	target_;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const &base);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &base);
	std::string	getTarget() const;
	void	execute(Bureaucrat const &executor) const;

};

#endif