/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:35:50 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/18 11:16:12 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <string>
# include <iostream>
# include <cstdlib>

template <class T> class	Array
{
	private:
		T	*elements_;
		unsigned int	size_;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &base);
		Array	&operator=(const Array &base);
		~Array();
		T	&operator[](unsigned int i);
		unsigned int	size() const;
		class	OutOfBoundsException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Error: Index out of bounds");
				}
		};
};

# include "Array.tpp"
#endif
