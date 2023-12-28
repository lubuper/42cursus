/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:55:02 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/28 17:38:46 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
	if (inputFile_.is_open())
		inputFile_.close();
	if (dbFile_.is_open())
		dbFile_.close();	
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

void	BitcoinExchange::treatInput(char *input)
{
	inputFile_.open(input);
	if (!inputFile_.is_open())
		throw (std::runtime_error("Error: couldn't open input file"));
	std::string line;
	std::getline(inputFile_, line);
	if (line != "date | value")
		return (std::cout << "Error: invalid format detected in line 1", void());
	while (std::getline(inputFile_, line))
	{
		if (line.find("|") == std::string::npos || !checkDate(line) || !checkValue(line))
			std::cout << "Error: bad input => " << line << std::endl;
	}
}

bool	BitcoinExchange::checkDate(std::string line)
{
	std::string::size_type pipe_pos = line.find("|");
	std::string::size_type dash_pos = line.find("-");
	if (dash_pos < 4)
		return (false);
	int	count = std::count(line.begin(), line.begin() + pipe_pos, '-');
	std::string	year = line.substr(0, dash_pos);
	std::string	month = line.substr(dash_pos + 1, 2);
	std::string	day = line.substr(dash_pos + 4, 2);
	if (!checkCalendar(year, month, day) || count != 2)
		return (false);
	return (true);
}

bool	BitcoinExchange::checkCalendar(std::string year, std::string month, std::string day)
{
	for (int i = 0; i < 4; i++)
		if (!isdigit(year.c_str()[i]))
			return (false);
	int y = atoi(year.c_str());
	if (!isdigit(month.c_str()[0]) || !isdigit(month.c_str()[1]) || isdigit(day.c_str()[0]) || !isdigit(day.c_str()[1]))
			return (false);
	int m = atoi(month.c_str());
	if (m < 1 || m > 12)
		return (false);
	int d = atoi(day.c_str());

	return (true);
}

bool	BitcoinExchange::checkValue(std::string value)
{
	(void)value;
	return (true);	
}

void	BitcoinExchange::printTable(std::string date, std::string value)
{
	(void)date;
	(void)value;
/* 	for (size_t i = 0; i < mapFilled_.size(); i++)
	{
			
	} */
}
