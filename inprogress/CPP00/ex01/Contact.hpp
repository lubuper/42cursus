/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:59:12 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/18 12:07:49 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <stdlib.h>

class Contact
{
private:
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;
	std::string	phonenumber;
	std::string	darkest_secret;
public:
	bool	exists;
	Contact();
	~Contact();
	std::string	getfirstname();
	std::string	getlastname();
	std::string	getnickname();
	std::string	getphonenum();
	std::string	getsecret();
	void	set_firstname(std::string str);
	void	set_lastname(std::string str);
	void	set_nickname(std::string str);
	void	set_pnumber(std::string str);
	void	set_secret(std::string str);
};

# define RED \033[31m
# define GREEN \033[32m
# define YELLOW \033[33m
# define BLUE \033[34m
# define MAGENTA \033[35m
# define CYAN \033[36m
# define WHITE \033[37m
# define DEFAULT \033[0m
# define BLINK \033[5;37m

#endif
