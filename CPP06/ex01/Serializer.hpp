/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:18:28 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/05 15:51:52 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"

class	Serializer
{
private:
	Serializer();
	Serializer(Serializer const &base);
	Serializer	&operator=(Serializer const &base);
public:
	~Serializer();
	static uintptr_t	serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif
