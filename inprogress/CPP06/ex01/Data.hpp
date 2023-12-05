/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:36:14 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/05 15:41:14 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>
# include <stdint.h>

typedef	struct
{
	std::string	name_;
	std::string	nick_;
	long int			clicks_;
	
}	Data;

#endif