/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:58:19 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/18 17:57:23 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

//----------------------------CONSTRUCTOR-------------------------------------
Contact::Contact(void)
{
	this->exists = false;
	return;
}

//----------------------------DESTRUCTOR--------------------------------------
Contact::~Contact(void)
{
	return;
}

//----------------------------GETTERS-----------------------------------------
std::string	Contact::getfirstname()
{
	return(firstname);
}

std::string	Contact::getlastname()
{
	return(lastname);
}

std::string	Contact::getnickname()
{
	return(nickname);
}

std::string	Contact::getphonenum()
{
	return(phonenumber);
}

std::string	Contact::getsecret()
{
	return(darkest_secret);
}

//----------------------------SETTERS-----------------------------------------
void	Contact::set_firstname(std::string str)
{
	firstname = str;
}

void	Contact::set_lastname(std::string str)
{
	lastname = str;
}

void	Contact::set_nickname(std::string str)
{
	nickname = str;
}

void	Contact::set_pnumber(std::string str)
{
	phonenumber = str;	
}

void	Contact::set_secret(std::string str)
{
	darkest_secret = str;
}
