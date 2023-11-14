/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:24:06 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/14 11:01:41 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* jeko = new Dog();
	const Animal* tareco = new Cat();
	const WrongAnimal* w = new WrongAnimal();
	const WrongAnimal* c = new WrongCat();

	std::cout << "\033[34m" << jeko->getType() << "\033[0m" << std::endl;
	std::cout << "\033[33m" << tareco->getType() << "\033[0m" << std::endl;
	tareco->makeSound(); //will output the cat sound!
	jeko->makeSound(); // will output the dog sound!
	meta->makeSound(); // will output default animal sound!

	std::cout << c->getType() << " " << std::endl;
	w->makeSound();
	c->makeSound();
	
	delete meta;
	delete jeko;
	delete tareco;
	delete w;
	delete c;
	return (0);
}