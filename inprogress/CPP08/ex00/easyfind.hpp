/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:09:05 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/14 13:53:50 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <map>
# include <iostream>
# include <list>
# include <vector>

class	NoOccurrenceException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{	
			return ("No occurrence was found.");
		}
};

template <typename T> void	easyfind(T *container, int seek);

# include "easyfind.tpp"

#endif