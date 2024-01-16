/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:55:02 by lde-sous          #+#    #+#             */
/*   Updated: 2024/01/16 17:03:10 by lde-sous         ###   ########.fr       */
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
		if (line.find("|") == std::string::npos)
			std::cout << "Error: bad input => " << line << std::endl;
		else
			checkAndPrint(line);
	}
}

void	BitcoinExchange::checkAndPrint(std::string line)
{
	std::string::size_type pipe_pos = line.find("|");
	std::string::size_type dash_pos = line.find("-");
	int	count = std::count(line.begin(), line.begin() + pipe_pos, '-');
	if (dash_pos < 4 || count != 2)
		return (std::cout << "Error: bad input => " << line << std::endl, void());
	std::string	year = line.substr(0, dash_pos);
	std::string	month = line.substr(dash_pos + 1, 2);
	std::string	day = line.substr(dash_pos + 4, 2);
	if (!checkCalendar(year, month, day))
		return ;
	checkValue(line);
}

bool	BitcoinExchange::checkCalendar(std::string year, std::string month, std::string day)
{
	//year
	for (int i = 0; i < 4; i++)
		if (!isdigit(year.c_str()[i]))
			return (std::cout << "Error: invalid year input" << std::endl, false);
	int y = atoi(year.c_str());
	if (y < 2009)
		return (std::cout << "Error: Bitcoin doesn't have a value on this date" << std::endl, false);
	//months
	for (int i = 0; i < 2; i++)
		if (!isdigit(month.c_str()[i]))
			return (std::cout << "Error: invalid month input" << std::endl, false);
	int m = atoi(month.c_str());
	if (m < 1 || m > 12)
		return (std::cout << "Error: invalid month input" << std::endl, false);
	//days
	for (int i = 0; i < 2; i++)
		if (!isdigit(day.c_str()[i]))
			return (std::cout << "Error: invalid day input" << std::endl, false);
	int d = atoi(day.c_str());
	if (d < 1 || d > 31)
		return (std::cout << "Error: invalid day input" << std::endl, false);
	if (y == 2009 && m == 1 && d == 1)
		return (std::cout << "Error: Bitcoin doesn't have a value on this date" << std::endl, false);
	if (m == 4 || m == 6 || m == 9 || m == 11)
	{
		if (d > 30)
			return (std::cout << "Error: invalid day input" << std::endl, false);
	}
	if (m == 2)
	{
		if (d == 29)
			if (y % 4 != 0 || y % 400 != 0)
				return (std::cout << "Error: invalid day input" << std::endl, false);
		if (d > 29)
			return (std::cout << "Error: invalid day input" << std::endl, false);
	}
	return (true);
}

void	BitcoinExchange::checkValue(std::string line)
{
	std::string::size_type pipe_pos = line.find("|");
	std::string inputvalue = line.substr(pipe_pos + 1);
	std::string	date = line.substr(0, pipe_pos);
	char	*endpointer;
	float	fvalue = std::strtod(inputvalue.c_str(), &endpointer);
	if (*endpointer != 0)
		return (std::cout << "Error: invalid input." << std::endl, void());
	if (fvalue < 0.0)
		return (std::cout << "Error: not a positive number." << std::endl, void());
	if (fvalue > 1000.0)
		return (std::cout << "Error: too large a number." << std::endl, void());
	else
		printResult(date, fvalue);
}

void	BitcoinExchange::printResult(std::string date, float value)
{
	std::map<std::string, float>::iterator	index;
	float	stockvalue;
	for (index = mapFilled_.begin(); index != mapFilled_.end(); index++)
	{
		if (index->first > date)
		{
			--index;
			stockvalue = index->second;
			break ;
		}
		if (index == mapFilled_.end())
		{
			--index;
			stockvalue = index->second;
		}
	}
	float	result = value * stockvalue;
	std::cout << date << "=> " << value << " = " << result << std::endl;
}
