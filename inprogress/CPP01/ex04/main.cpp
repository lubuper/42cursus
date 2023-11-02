/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:10:40 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/02 15:03:26 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <istream>
#include <iostream>
#include <string>

std::string	seekAndDest(std::string line, const std::string s1, const std::string s2)
{
	std::size_t	index = 0;
	const std::string	temp = line;
	while(1)
	{
		index = temp.find(s1, index);
		if (index == std::string::npos)
			break ;
		line.erase(index, s1.size());
		line.insert(index, s2);
		index += s2.size();
	}
	return (line);
}

int	main(int ac, char **av)
{
	if (ac != 4 || (!av[2][0] || !av[3][0]))
		return (std::cout << "Error: invalid arguments" << std::endl, 1);
	else
	{
		std::fstream inFile;
		std::fstream outFile;
		const std::string s1 = av[2];
		const std::string s2 = av[3];
		std::string	line = std::string(av[1]) + ".replace";

		inFile.open(av[1], std::ios::in);
		outFile.open(line.c_str(), std::ios::out);
		if (!inFile || !outFile)
			return (std::cout << "Error: cannot open file" << std::endl, 1);
		while (getline(inFile, line))
		{
			line = seekAndDest(line, s1, s2);
			outFile << line << std::endl;
		}
		inFile.close();
		outFile.close();
	}
	return (0);
}
