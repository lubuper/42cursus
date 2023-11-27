/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:59:30 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/27 10:21:31 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class	Bureaucrat;

class	RobotomyRequestForm : public AForm
{
private:
	std::string	target_;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const &base);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &base);
	std::string	getTarget() const;
	void	execute(Bureaucrat const &executor) const;
};

std::ostream	&operator<<(std::ostream &COUT, RobotomyRequestForm const &base);

#endif
