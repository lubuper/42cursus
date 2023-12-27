/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:55:02 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/27 20:31:31 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &base)
{
	*this = base;
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &base)
{
	if (this != &base)
	{
		mapFilled_.clear();
		mapFilled_ = base.mapFilled_;
	}
	return (*this);
}

void	BitcoinExchange::treatDb(void)
{
	dbFile_.open("data.csv");
	if (!dbFile_.is_open())
		throw (std::runtime_error("Error: couldn't open data.csv"));
	std::string	data_line;
	std::string	date_instring;
	std::string value_instring;
	size_t		comma_index;
	float		value;
	
	std::getline(dbFile_, data_line);
	while(std::getline(dbFile_, data_line))
	{
		comma_index = data_line.find(",");
		date_instring = data_line.substr(0, comma_index);
		value_instring = data_line.substr(comma_index + 1, data_line.size());
		value = std::atof(value_instring.c_str());
		mapFilled_[date_instring] = value;
	}
}

bool	BitcoinExchange::checkDate(std::string line)
{
	
	return (true);
}

bool	BitcoinExchange::checkYear(std::string year)
{
	return (true);
}

bool	BitcoinExchange::checkMonth(std::string month)
{
	return (true);
}

bool	BitcoinExchange::checkDay(std::string day)
{
	return (true);
}

bool	BitcoinExchange::checkValue(std::string value)
{
	return (true);	
}

void	BitcoinExchange::printTable(std::string date, std::string value)
{
		
}
