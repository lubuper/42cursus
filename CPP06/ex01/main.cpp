/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:40:55 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/06 12:43:15 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data	table;

	table.clicks_ = 50;
	table.name_ = "advertisement";
	table.nick_ = "clickbait";
	uintptr_t	pointer = Serializer::serialize(&table);
	Data	*newtable = Serializer::deserialize(pointer);

	std::cout << "&table = " << table.name_ << std::endl;
	std::cout << "&newtable name = " << newtable->name_ << std::endl;
	std::cout << "&newtable nick = " << newtable->nick_ << std::endl;
	table.clicks_ = 54;
	std::cout << "&newtable clicks = " << newtable->clicks_ << std::endl;
	return (0);
}
