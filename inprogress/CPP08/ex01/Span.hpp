/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:38:19 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/18 14:02:24 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <string>
# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include <map>

class	Span
{
	private:
		unsigned int		storage_;
		std::vector<int>	nums_;
	public:
		Span();
		Span(unsigned int N);
		Span(Span const &base);
		Span &operator=(Span const &base);
		~Span();
		void	addNumber(int number);
		int		shortestSpan();
		int		longestSpan();
		class	MaxStorageException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Error: object storage overload.");
				}
		};
		class	NoSpanException : public std::exception
		{
			public:
					virtual const char *what() const throw()
					{
						return ("Error: invalid input to calculate span");
					}
		};
};

#endif