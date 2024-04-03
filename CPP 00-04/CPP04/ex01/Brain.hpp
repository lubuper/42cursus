/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:09:51 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/14 12:40:32 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <istream>
# include <iostream>
# include <string>

class	Brain
{
private:
	std::string	ideas[100];
public:
	Brain();
	~Brain();
	Brain(const Brain &base);
	Brain &operator=(const Brain &base);

};

#endif