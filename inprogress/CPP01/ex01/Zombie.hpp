/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:37:36 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/20 20:53:36 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>
# include <istream>

class	Zombie
{
private:
	std::string	name;	
public:
	Zombie();
	~Zombie();
	void	announce(void);
	std::string	name_getter(void);
	std::string	name_setter(std::string str);
};

Zombie	*zombieHorde(int N, std::string name);


#endif