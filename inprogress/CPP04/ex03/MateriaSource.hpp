/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:43:42 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/22 10:55:29 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
private:
	AMateria	*inventory[4];
public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource &base);
	MateriaSource &operator=(const MateriaSource &base);
	void	learnMateria(AMateria*);
	AMateria	*createMateria(std::string const & type);
};

#endif