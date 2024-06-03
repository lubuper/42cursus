/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:23:59 by lde-sous          #+#    #+#             */
/*   Updated: 2024/02/05 19:23:59 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/webserv.hpp"

/**
 * @brief Checks if a given string represents a numeric value.
 *
 * @param str The string to be checked.
 * @return true if the string represents a numeric value, false otherwise.
 */
bool isNumeric(std::string str) 
{
	for (size_t i = 0; i < str.length(); i++)
		if (!std::isdigit(str[i]))
			return false;
	return true;
}

/**
 * @brief Removes occurrences of the substring " ;" (space followed by semicolon) from the given string.
 *
 * @param str The string from which the substring is to be removed.
 */
void	eraseSemicolon(std::string &str) 
{
	size_t i = str.find(" ;");
	if (i != std::string::npos)
		str.erase(i, 2);
}

/**
 * @brief Converts a string IP address to its corresponding unsigned integer representation.
 *
 * @param addr The string representation of the IP address.
 * @return The unsigned integer representation of the IP address.
 */
unsigned int	convertIP(const std::string& addr) 
{
	std::istringstream iss(addr);
	std::string token;
	unsigned int result = 0;
	for (int i = 0; i < 4; i++) 
	{
		if (!std::getline(iss, token, '.') || token.empty())
			return (0);
		int octet = atoi(token.c_str());
		if (octet < 0 || octet > 255)
			return (0);
		result = (result << 8) | octet;
	}
	return (result);
}

/**
 * @brief Converts an unsigned integer IP address to its string representation.
 *
 * @param addr The unsigned integer representation of the IP address.
 * @return The string representation of the IP address.
 */
std::string ipToStr(unsigned int addr) 
{
    std::ostringstream oss;
    oss << ((addr >> 24) & 0xFF) << '.' << ((addr >> 16) & 0xFF) << '.' << ((addr >> 8) & 0xFF) << '.' << (addr & 0xFF);
    if (oss.str() == "0.0.0.0")
		return "localhost";
	return oss.str();
}

/**
 * @brief Extracts values from a string vector based on whether it represents directory or file information.
 *
 * @param it Iterator pointing to the current position in the string vector.
 * @param body The string vector containing configuration data.
 * @param IsDir Flag indicating whether the data represents directory information (true) or file information (false).
 * @return std::vector<std::string> containing extracted values.
 */
std::vector<std::string> extractValues(std::vector<std::string>::iterator& it, const std::vector<std::string>& body, bool IsDir) {
	std::vector<std::string> values;
	if (IsDir) 
	{
		if (*it == "location" && ((*(it + 1)).find("*") != std::string::npos || (*(it + 1)).find(".") != std::string::npos)) 
		{
			while (it != body.end() && *it != "}") 
			{
				if (*it == "{" || *it == "}")
					it++;
				values.push_back(*it);
				it++;
			}
		} 
		else 
		{
			while (it != body.end() && *it != ";") 
			{
				if (*it == "{" || *it == "}")
				{
					if (*it == "}")
						break ;
					it++;
				}
				values.push_back(*it);
				it++;
			}
		}
	}
	else 
	{
		while (it != body.end() && *it != "}") 
		{
			if (*it == "{" || *it == "}")
					it++;
			values.push_back(*it);
			it++;
		}
	}
	return (values);
}

/**
 * @brief Converts an integer to its string representation.
 *
 * @param number The integer to be converted.
 * @return The string representation of the integer.
 */
std::string intToStr(int number) 
{
	char buffer[20];
	sprintf(buffer, "%d", number);
	return (std::string(buffer));
}

/**
 * @brief Creates a directory specified by the given path.
 *
 * @param path The path of the directory to be created.
 * @return true if the directory is created successfully, false otherwise.
 */
bool createDirectory(const char *path) 
{
	struct stat st;
	if (stat(path, &st) == 0)
		return true;
	if (mkdir(path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == 0)
		return true;
	return false;
}

/**
 * @brief Creates and returns a map containing keyword mappings specific to the configuration file format.
 *
 * @return std::map<std::string, std::string> containing keyword mappings.
 */
std::map<std::string, std::string> createLocalKeyMap() 
{
	std::map<std::string, std::string> keyMap;
	keyMap.insert(std::make_pair("dir", "allow_methods root redirect alias index autoindex"));
	keyMap.insert(std::make_pair("file", "allow_methods cgi_pass"));
	return (keyMap);
}

void slowCout(const std::string& str)
{
	for (size_t i = 0; i < str.size(); ++i)
	{
		std::cout << str[i];
		usleep(50000);
	}
}