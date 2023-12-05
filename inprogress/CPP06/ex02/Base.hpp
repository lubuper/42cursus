/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:32:27 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/05 17:48:22 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <string>
# include <iostream>
# include <ctime>

class	Base
{
public:
	virtual ~Base();
};

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif