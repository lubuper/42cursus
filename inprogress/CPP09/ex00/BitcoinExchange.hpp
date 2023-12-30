/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:42:01 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/29 16:31:51 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <string>
# include <fstream>
# include <algorithm>
# include <cstdlib>

class	BitcoinExchange
{
	private:
		std::map<std::string, float>	mapFilled_;
		std::fstream	inputFile_;
		std::fstream	dbFile_;
	public:
		BitcoinExchange();	
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &base);
		BitcoinExchange	&operator=(BitcoinExchange const &base);
		void	treatDb(void);
		void	checkAndPrint(std::string line);
		bool	checkCalendar(std::string year, std::string month, std::string day);
		void	checkValue(std::string line);
		void	printResult(std::string date, float value);
		void	treatInput(char *input);		
};

#endif