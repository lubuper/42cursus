/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:22:20 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/21 18:44:05 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <string>
# include <iostream>
# include <algorithm>
# include <vector>
# include <deque>
# include <list>
# include <stack>

template <typename T>
class	MutantStack : public std::stack<T>
{
	public:
		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::const_iterator const_iterator;
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack &base);
		MutantStack	&operator=(const MutantStack &base);
		iterator	it_begin(void);	
		iterator	it_end(void);
		const_iterator	c_it_begin(void);
		const_iterator	c_it_end(void);
};

# include "MutantStack.tpp"

#endif