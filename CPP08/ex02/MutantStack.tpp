/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:22:33 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/21 20:33:48 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &base) : std::stack<T>(base)
{
}

template <typename T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack &base)
{
	std::stack<T>::operator=(base);
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::it_begin(void)
{
	return (std::stack<T>::c.begin());
}	

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::it_end()
{
	return (std::stack<T>::c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::c_it_begin()
{
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::c_it_end()
{
	return (std::stack<T>::c.end());
}

#endif