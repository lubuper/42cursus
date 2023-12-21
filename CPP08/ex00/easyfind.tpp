/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:09:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/21 19:43:30 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

template <typename T>
void	easyfind(T container, int seek)
{
	typename T::iterator	pointer;
	pointer = std::find(container.begin(), container.end(), seek);
	if (pointer != container.end())
		std::cout << seek << " was found." << std::endl;
	else
		throw (NoOccurrenceException());
}

#endif