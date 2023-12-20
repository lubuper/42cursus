/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:11:17 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/07 15:28:11 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

# include <string>
# include <iostream>

template	<typename var> void swap(var& x, var& y)
{
		var	temp;
		temp = x;
		x = y;
		y = temp;
}

template	<typename var> var min(var& x, var& y)
{
	return (x > y ? y : x);
}

template	<typename var> var max(var& x, var& y)
{
	return (x > y ? x : y);
}

#endif