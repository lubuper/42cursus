/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:40:53 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/30 12:06:54 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <cstdlib>
# include <climits>
# include <cmath>
# include <iostream>

class	ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &base);
	ScalarConverter &operator=(ScalarConverter const &base);
public:
	~ScalarConverter();
	void	convert(std::string const input);
};

#endif