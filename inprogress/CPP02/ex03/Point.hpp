/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:59:36 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/10 19:02:17 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point
{
private:
	Fixed const	x;
	Fixed const	y;
public:
	Point();
	Point(Fixed const x, Fixed const y);
	Point(Point	const &base)
	~Point();
};

#endif