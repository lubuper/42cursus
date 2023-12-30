/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:51:35 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/29 18:55:41 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <stack>
# include <algorithm>

class	RPN
{
	private:
		std::stack<double>	arr_;
	public:
		RPN();
		~RPN();
		RPN(RPN const &base);
		RPN	&operator=(RPN const &base);
		void	fillstack(std::string parameters);
		double	executeRPN(char m_operator);
};
#endif