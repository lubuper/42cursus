/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:19:32 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/18 12:24:35 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:

public:
	Contact list[8];
	PhoneBook();
	~PhoneBook();
	void		add_func(void);
	void		startup_func(std::string user);
	void		displayindex_func(void);
	void		search_func(void);
	void		parser(std::string _input, int attribute_no, Contact *list);
	std::string	truncate(std::string str);
};


#endif
