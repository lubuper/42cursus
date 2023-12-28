/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:42:01 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/28 17:36:54 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <string>
# include <fstream>
# include <algorithm>

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
		bool	checkDate(std::string line);
		bool	checkCalendar(std::string year, std::string month, std::string day);
		bool	checkValue(std::string value);
		void	printTable(std::string date, std::string value);
		void	treatInput(char *input);		
};

#endif