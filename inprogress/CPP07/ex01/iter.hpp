/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:42:21 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/07 18:39:52 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <string>
# include <iostream>
# include <istream>

template <typename var, typename var2> void iter(var* arr, size_t len, var2 func)
{
	for(size_t i = 0; i < len; i++)
		func(arr[i]);
}

#endif