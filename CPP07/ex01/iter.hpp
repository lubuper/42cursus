/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:42:21 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/18 11:18:00 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <string>
# include <iostream>
# include <istream>
# include <cstdlib>

template <typename v> void iter(v* arr, size_t len, void (*func)(v &))
{
	for(size_t i = 0; i < len; i++)
		func(arr[i]);
}

template <typename v> void printit(v &something)
{
	std::cout << something << " ";
}

template <typename T> void fun(T &var)
{
	var = 47;
}

#endif