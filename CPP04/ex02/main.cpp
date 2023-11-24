/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:24:06 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/24 17:50:45 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	//Animal	test;
	
	std::cout << "\n\033[32m------Creating \033[33mNew\033[0m Cat:" << std::endl;
	const Cat* originalA = new Cat();
	std::cout << "\n\033[32m------Copying a \033[33mNew\033[0m Cat from the original:" << std::endl;
	const Cat* copyA = new Cat(*originalA);
	std::cout << "\n\033[32m------Creating \033[33mNew\033[0m Dog:" << std::endl;
	const Dog* doggy = new Dog();
	{
		std::cout << "\n\033[32m------Copying a \033[33mNew \033[34mDog from the original on a specific scope:\033[0m" << std::endl;
		const Dog* temporary = new Dog(*doggy);
		std::cout << "\n\033[32m------Example of type: \033[0m" << temporary->getType() << std::endl;
		std::cout << "\n\033[32m------\033[31mDeleting \033[0m Dog temporary:" << std::endl;
		delete temporary;
		std::cout << "\n\033[32m------\033[34m//End of scope//\033[0m" << std::endl;
		std::cout << std::endl;
	}
	originalA->makeSound();
	copyA->makeSound();
	doggy->makeSound();
	std::cout << "\n\033[32m------\033[31mDeleting \033[0m Cat copy:" << std::endl;
	delete copyA;
	std::cout << "\n\033[32m------\033[31mDeleting \033[0m Cat original:" << std::endl;
	delete originalA;
	std::cout << "\n\033[32m------\033[31mDeleting \033[0m Dog original:" << std::endl;
	delete doggy;
}
