/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardon.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:58:46 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/28 16:45:20 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDON_HPP
# define PRESIDENTIALPARDON_HPP

# include "AForm.hpp"

class	Bureaucrat;

class	PresidentialPardon : public AForm
{
private:
	std::string	target_;
public:
	PresidentialPardon();
	PresidentialPardon(std::string target);
	~PresidentialPardon();
	PresidentialPardon(PresidentialPardon const &base);
	PresidentialPardon &operator=(PresidentialPardon const &base);
	std::string	getTarget() const;
	void	execute(Bureaucrat const &executor) const;

};

#endif