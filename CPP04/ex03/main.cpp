/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:39:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/24 15:43:10 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"


int main()
{
 	IMateriaSource* chest = new MateriaSource();
	IMateriaSource* river = new MateriaSource();
	chest->learnMateria(new Ice());
	river->learnMateria(new Cure());
	ICharacter* me = new Character("Ferclaw");
	ICharacter* bob = new Character("bob");
	AMateria* tmp;
	AMateria* tmp2;
	AMateria* tmp3;
	AMateria* tmp4;
	AMateria* tmp5;
	tmp = chest->createMateria("ice");
	tmp2 = river->createMateria("cure");
	tmp3 = chest->createMateria("Resurrection");
	tmp4 = chest->createMateria("Ice Blast");
	tmp5 = chest->createMateria("IceMageddon");
	std::cout << "\033[32m---------------------------\033[0m" << std::endl;
	me->equip(tmp);
	me->equip(tmp2);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(1, *me);
	std::cout << "\033[32m---------------------------\033[0m" << std::endl;
	delete bob;
	delete me;
	delete river;
	delete chest;
	
/* 	Ice	i = Ice();

	std::cout << i.getType() << std::endl; */
	
	
}