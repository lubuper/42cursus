/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Configuration.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:36:38 by lde-sous          #+#    #+#             */
/*   Updated: 2024/02/05 16:36:38 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIGURATION_HPP
# define CONFIGURATION_HPP

# pragma once
# include "../webserv.hpp"
# include "../structures.hpp"
# include "../server/Server.hpp"
#include <filesystem>

class Server;

class Configuration {

	private:
		std::stack<std::string> _svBlocks;
		std::vector<int>		_ports;

	public:
		Configuration();
		Configuration(const std::string& path);
		Configuration(const Configuration& original);
		Configuration& operator=(const Configuration& original);
		~Configuration();
		std::stack<std::string>& getSvBlocks();
		void setSvBlocks(std::ifstream& file);
		void	checkSemicolon(std::vector<std::string>& body);
		void	checkSvName(std::vector<std::string>& body, t_server_config& conf);
		void	processListen(std::istringstream& iss, t_listen& listen);
		void	checkSvRoot(std::vector<std::string>& body, t_server_config& conf);
		void	checkErrPage(std::vector<std::string>& body, t_server_config& conf);
		void	checkIndex(std::vector<std::string>& body, t_server_config& conf);
		void	checkMethods(std::vector<std::string>& body, t_server_config& conf);
		void	checkClientBodySize(std::vector<std::string> &body, t_server_config &conf);
		void	checkLocations(Server* server, std::vector<std::string>& body, t_server_config& conf);
		void	processLocationDir(std::vector<std::string>::iterator& it, std::vector<std::string>& body, t_server_config& conf);
		int		setKeywordsDir(std::vector<std::string> values, BaseLocation& strc);
		int		setKeywordsFile(std::vector<std::string> values, BaseLocation& strc);
		int		checkKeywords(std::vector<std::string>& body);
		int		setKeywords(std::string type, std::vector<std::string> key, BaseLocation& strc);
		void	checkDoubles(std::vector<std::string>& body);

		class ConfigurationException : public std::exception
		{
			private:
				std::string _errMessage;
			public:
				ConfigurationException(const std::string& error);
				~ConfigurationException() throw();
				virtual const char* what() const throw();
		};

};

#endif
