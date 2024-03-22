/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:36:38 by lde-sous          #+#    #+#             */
/*   Updated: 2024/02/05 16:36:38 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/config/Config.hpp"

/* ===================== Orthodox Canonical Form ===================== */

Config::Config() {}

Config::Config(const Config& original) {
	_serverBlocks = original._serverBlocks;
}

Config& Config::operator=(const Config& original) {
	_serverBlocks = original._serverBlocks;
	return (*this);
}

Config::~Config() {}

/* ===================== Constructors ===================== */

Config::Config(std::string filePath) {
	try {
		std::ifstream file(filePath.c_str());
		if (!file.is_open())
			throw ConfigFileException("Cannot access file.");
		setServerBlocks(file);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
	}
}

/* ===================== Getter Functions ===================== */

std::stack<std::string>& Config::getServerBlocks() {
	return (_serverBlocks);
}

/* ===================== Setter Functions ===================== */

struct IsSpace {
    bool operator()(char c) const {
        return std::isspace(c) && c != ' ';
    }
};

/**
 * @brief Parses the configuration file to extract server block information.
 *
 * This method reads lines from the configuration file and identifies server blocks
 * based on the presence of specific keywords, such as "server" and "server_name".
 * It ensures the syntactic correctness of the server blocks by tracking the number
 * of opening and closing curly braces ({}) within each block. The extracted server
 * block information is stored in a stack for further processing.
 *
 * @throws FileAccessException If an invalid server block is encountered, i.e.,
 *                             the number of opening and closing curly braces
 *                             does not match.
 */
void	Config::setServerBlocks(std::ifstream& file) {
	try {
		std::string	line, buffer;
		int	flag = 0, openBracket = 0, closeBracket = 0;
		while (std::getline(file, line)) {
			std::replace_if(line.begin(), line.end(), IsSpace(), ' ');
			if (line.find("server_name") != std::string::npos && flag < 2) {
				buffer += line;
				flag++;
			}
			else if (line.find("server") != std::string::npos && flag < 1) {
				buffer += line;
				flag++;
			}
			else if (line.find("server") != std::string::npos && flag <= 2) {
				openBracket += std::count(buffer.begin(), buffer.end(), '{');
				closeBracket += std::count(buffer.begin(), buffer.end(), '}');
				if (openBracket != closeBracket)
					throw ConfigFileException("Invalid server block.");
				_serverBlocks.push(buffer);
				buffer.clear();
				buffer += line;
				flag = 1;
			}
			else
				buffer += line;
		}
		_serverBlocks.push(buffer);
		buffer.clear();
	} catch (std::exception &e) {
       std::cout << e.what() << std::endl;
    }
}


/* ===================== Member Functions ===================== */

/**
 * @brief Parses the configuration to check for correct semicolon placement.
 *
 * @param body The body of the configuration to parse.
 */
void	Config::parseSemicolon(std::vector<std::string>& body) {
	std::vector<std::string>::iterator it;
	std::istringstream keywords(KEYWORDS);
	std::string word;
	if (body.size() > 3 && body[0] == "server" && body[1] == "{" && body[2] == "listen") {
		while (keywords >> word)
			for (it = body.begin() + 3; it != body.end(); it++)
				if (*it == word && (*(it - 1) != ";" && *(it - 1) != "{" && *(it - 1) != "}"))
					throw ConfigFileException("Endline delimitor wrong/missing");
				else if (*it == "}" && (*(it - 1) != ";" && *(it - 1) != "}"))
					throw ConfigFileException("Endline delimitor wrong/missing");
		return ;
	}
	throw ConfigFileException("Server Block not configured correctly.");
}

/**
 * @brief Parses the server name from the configuration body.
 *
 * @param body The body of the configuration to parse.
 * @param conf The server configuration structure to store the parsed server name.
 */
void	Config::parseServerName(std::vector<std::string>& body, t_server_conf& conf)
{
	std::vector<std::string>::iterator it;

	for (it = body.begin(); it != body.end(); it++) {
		if (*it == "location") {
			conf.server_name.push_back("_");
			break;
		}
		else if (*it == "server_name") {
			it++;
			while (*it != ";") {
				conf.server_name.push_back(*it);
				it++;
			}
			break ;
		}
	}
	if (conf.server_name.size() != 1)
		throw ConfigFileException("Multiple server names defined in file.");
}


/**
 * @brief Parses the listen directive from the configuration body.
 *
 * @param iss The input string stream to read from.
 * @param listen The structure to store the parsed listen configuration.
 */
void Config::parseListen(std::istringstream& iss, t_listen& listen) {
	std::string word, address, temp_str;
	size_t pos;
	while (iss >> word) {
		if (word == "listen") {
			iss >> address;
			pos = address.find(":");
			if (pos != std::string::npos) {
				temp_str = address.substr(address.find(":") + 1);
				removeSemiColon(temp_str);
				!isNumeric(temp_str) ? throw ConfigFileException("Port wrongly formatted => " + temp_str) : 0;
				listen.port = atoi(temp_str.c_str());
				if (listen.port <= 0 || listen.port >= 65535)
					throw ConfigFileException("Port out of range => " + intToStr(listen.port));
				temp_str = address.substr(0, pos);
				if (temp_str == "0.0.0.0")
					listen.host = INADDR_ANY;
				else {
					listen.host = convertAddr(temp_str);
					!listen.host ? throw ConfigFileException("Couldn't convert host => " + temp_str) : 0;
				}
			}
			else {
				listen.host = INADDR_ANY;
				removeSemiColon(address);
				!isNumeric(address) ? throw ConfigFileException("Port wrongly formatted => " + address) : 0;
				listen.port = atoi(address.c_str());
				if (listen.port <= 0 || listen.port >= 65535)
					throw ConfigFileException("Port out of range => " + intToStr(listen.port));
			}
		}
	}
}


/**
 * @brief Parses the server root directive from the configuration body.
 *
 * @param body The body of the configuration to parse.
 * @param conf The server configuration structure to store the parsed server root.
 */
void	Config::parseServerRoot(std::vector<std::string>& body, t_server_conf& conf) {
	std::vector<std::string>::iterator it;
	for (it = body.begin(); it != body.end(); it++) {
		if (*it == "root") {
			it++;
			conf.server_root = *it;
			break ;
		}
		else if (*it == "location")
			break ;
	}
	std::ifstream file(conf.server_root.c_str());
    !file.good() ? throw ConfigFileException("Path does not exist => " + conf.server_root) : 0;
}

/**
 * @brief Parses the error page directives from the configuration body.
 *
 * @param body The body of the configuration to parse.
 * @param conf The server configuration structure to store the parsed error pages.
 */
void	Config::parseErrorPage(std::vector<std::string>& body, t_server_conf& conf)
{
	int count = 0;
	std::string errorPath;
	(void) conf;
	std::map<int, std::string> errorPages;
    for (size_t i = 0; i < body.size(); ++i)
	{
		if(body[i] == "location" )
			break;
		if (body[i] == "error_page")
		{
			count++;
			while(body[i] != ";")
				i++;
			i--;
			if(body[i][0] == '/')
				errorPath = body[i];
			while(body[--i] != "error_page")
			{
				int errorCode = atoi(body[i].c_str());
				conf.errorPages.insert(std::make_pair(errorCode, errorPath));
			}
		}
	}
    /* WORKING! // Print the contents of the map
    std::cout << "Error Pages:" << std::endl;
    std::map<int, std::string>::const_iterator it;
    for (it = conf.errorPages.begin(); it != conf.errorPages.end(); ++it)
    {
        std::cout << "Error Code: " << it->first << ", Error Path: " << it->second << std::endl;
    } */
}

/**
 * @brief Parses the index directive from the configuration body.
 *
 * @param body The body of the configuration to parse.
 * @param conf The server configuration structure to store the parsed index files.
 */
void	Config::parseIndex(std::vector<std::string>& body, t_server_conf& conf) {
	std::vector<std::string>::iterator it;
	for (it = body.begin(); it != body.end(); it++) {
		if (*it == "location")
			break ;
		else if (*it == "index") {
			it++;
			conf.index.clear();
			while (*it != ";") {
				conf.index.push_back(*it);
				it++;
			}
			break ;
		}
	}
}

/**
 * @brief Parses the allow_methods directive from the configuration body.
 *
 * @param body The body of the configuration to parse.
 * @param conf The server configuration structure to store the parsed allowed methods.
 */
void	Config::parseMethods(std::vector<std::string>& body, t_server_conf& conf) {
	std::vector<std::string>::iterator it;
	for (it = body.begin(); it != body.end(); it++) {
		if (*it == "location")
			throw ConfigFileException("'location' before 'allow_methods' in config file");
		else if (*it == "allow_methods") {
			it++;
			while (*it != ";") {
				if (*it != "GET" && *it != "POST" && *it != "DELETE")
					throw ConfigFileException("undefined method in config file => " + *it);
				conf.allow_methods.push_back(*it);
				it++;
			}
			break ;
		}
	}
}

void	Config::parseClientSize(StringVector &body, t_server_conf &conf)
{
	std::vector<std::string>::iterator it;
	for (it = body.begin(); it != body.end(); it++) {
		if (*it == "client_max_body_size") {
			if(!isNumeric(*(it + 1)))
				throw ConfigFileException("invalid client_max_body_size => " + *(it + 1));
			int	client_body_size_value = atoi((*(it + 1)).c_str());
			if (client_body_size_value <= 0 || client_body_size_value > 1024)
				throw ConfigFileException("invalid client_max_body_size => " + intToStr(client_body_size_value));
			conf.client_max_body_size = client_body_size_value;
			return;
		}
	}
}

/**
 * @brief Parses the locations block from the configuration body.
 *
 * @param server Pointer to the Server instance.
 * @param body The body of the configuration to parse.
 * @param conf The server configuration structure to store the parsed locations.
 */
void	Config::parseLocations(Server* server, std::vector<std::string>& body, t_server_conf& conf) {
	std::vector<std::string>::iterator it;
	int bracketCounter = 0;
	if (checkMandatoryKeywords(body) == -1)
		throw ConfigFileException("Invalid alias or methods.");
	for (it = body.begin(); it != body.end(); it++) {
		if (*it == "location") {
			it++;
			if (it != body.end() && (*it).find("/") != std::string::npos) {
				LocationDir* newDir = new LocationDir;
				newDir->name = *it;
				conf.locationStruct.push_back(newDir);
				it++;
				while (it != body.end()) {
					if (*it == "location" && (*(it + 1)).find("/") != std::string::npos) {
						it--;
						break ;
					}
					else if (*it == "{" || *it == "}")
						bracketCounter++;
					else if (*it == "location" && ((*(it + 1)).find("*") != std::string::npos || (*(it + 1)).find(".") != std::string::npos))
						if (*(it + 2) == "{" && (bracketCounter + 1) % 2 != 0) {
							it--;
							break ;
						}
					if (*it != "}") {
						StringVector values = extractValues(it, body, true);
						setKeywordValue("dir", values, *(conf.locationStruct.back()));
					}
					it++;
				}
				if (it == body.end())
					break ;
			}
			else if ((*it).find("*") != std::string::npos || (*it).find(".") != std::string::npos) {
				LocationFiles* newFile = new LocationFiles;
				newFile->name = *it;
				conf.locationStruct.push_back(newFile);
				it++;
				while (it != body.end() && *it != "location") {
					if (*it != "}") {
						StringVector values = extractValues(it, body, true);
						setKeywordValue("file", values, *(conf.locationStruct.back()));
					}
					it++;
				}
				if (it == body.end())
					break ;
				it--;
			}
		}
	}
	printLogs(server, conf);
}

/**
 * @brief Checks for mandatory keywords in the configuration body.
 *
 * @param body The body of the configuration to check.
 * @return -1 if mandatory keywords are missing, 0 otherwise.
 */
int	Config::checkMandatoryKeywords(std::vector<std::string>& body) {
	std::vector<std::string>::iterator it;
	for (it = body.begin(); it != body.end(); it++) {
		if (*it == "alias" && *(it + 1) == ";")
			return (-1);
		else if (*it == "allow_methods") {
			it++;
			if (*it == ";")
				return (-1);
			while (*it != ";") {
				if (*it != "GET" && *it != "POST" && *it != "DELETE")
					return (-1);
				it++;
			}
		}
		else if (*it == "cgi_pass" && *(it + 1) == ";")
			return (-1);
	}
	return (0);
}

/**
 * @brief Sets the value of a keyword in the location structure.
 *
 * @param type The type of location structure (dir or file).
 * @param values The values associated with the keyword.
 * @param strc The location structure to set the value in.
 */
void	Config::setKeywordValue(std::string type, StringVector values, LocationStruct& strc) {
	std::istringstream iss(createLocalKeyMap()[type]);
	std::string word;
	std::string LocationDir::*data[3] = {
		&LocationDir::alias,
		&LocationDir::redirect,
		&LocationDir::root
	};
	std::string key[3] = {
		"alias",
		"redirect",
		"root"
		// CHECK THESE KEYS TO MATCH THE SEARCH OPTIONS FOR LOCATION SUB DIRECTIVES!!!
	
	};

	StringVector::iterator values_it = values.begin() + 1;
	if (values.empty())
		return ;
	if (type == "dir") {
		LocationDir* dir = dynamic_cast<LocationDir*>(&strc);
		if (dir) {
			while (iss >> word) {
				for (int i = 0; i < 3; i++) {
					if (values[0] == key[i]) {
						dir->*data[i] = values[1];
						return ;
					}
				}
				if (values[0] == word && word == "index") {
					while (values_it != values.end()) {
						dir->index.push_back(*values_it);
						values_it++;
					}
				}
				else if (values[0] == word && word == "allow_methods") {
					while (values_it != values.end()) {
						dir->allow_methods.push_back(*values_it);
						values_it++;
					}
				}
/* 	TESTING			else if (values[0] == word && word == "alias") {
					if ((values_it + 1) != values.end()) {
						std::cout << "Testing values - " << *values_it << std::endl;
						if (*(values_it + 1) == "alias")
							throw ConfigFileException("Duplicate 'alias' in config file.");
						dir->alias = *values_it;
						values_it++;
					}
	END OF TEST			}*/
				else if (values[0] == "location" && ((values[1].find("*") != std::string::npos) || values[1].find(".") != std::string::npos)) {
					while (iss >> word && *values_it != "}" && values_it != values.end()) {
						LocationFiles* newFile = new LocationFiles;
						newFile->name = values[1];
						values_it++;
						dir->files.push_back(newFile);
						if (*values_it != "}") {
							StringVector extract = extractValues(values_it, values, false);
							setKeywordValue("file", extract, *dir->files.back());
							return ;
						}
					}
				}
			}
		}
	}
	else if (type == "file") {
		LocationFiles *file = dynamic_cast<LocationFiles*>(&strc);
		if (file) {
			while (iss >> word) {
				if (values[0] == word && word == "cgi_pass") {
					file->cgi_pass = values[1];
					values_it++;
					if (values_it != values.end()) {
						values_it++;
						if (*values_it == "allow_methods") {
							while (values_it != values.end() && *values_it != ";") {
								file->allow_methods.push_back(*values_it);
								values_it++;
							}
						}
					}
				}
				else if (values[0] == word && word == "allow_methods") {
					while (values_it != values.end() && *values_it != ";") {
						file->allow_methods.push_back(*values_it);
						values_it++;
					}
					while (values_it != values.end()) {
						if (*values_it == "cgi_pass") {
							file->cgi_pass = *(values_it + 1);
						}
						values_it++;
					}
				}
			}
		}
	}
}


void	Config::checkDoubles(std::vector<std::string>& body)
{
	std::map<std::string, int> countTable;
	std::set<std::string> keywords;
	keywords.insert("index");
	keywords.insert("root");
	keywords.insert("client_max_body_size");
	keywords.insert("allow_methods");
	keywords.insert("alias");
	keywords.insert("server_name");
	keywords.insert("cgi_pass");
	for (std::vector<std::string>::iterator it = body.begin(); it != body.end(); it++) {
		if ((*it) == "location" && it + 1 != body.end()) {
			std::vector<std::string> newBody(it + 1, body.end());
			checkDoubles(newBody);
			break ;
		}
		if (keywords.find(*it) != keywords.end())
			countTable[*it]++;
	}
	for (std::map<std::string, int>::iterator mit = countTable.begin(); mit != countTable.end(); mit++)
		if (mit->second > 1)
			throw ConfigFileException("Duplicate '" + mit->first + "' directive in config file.");
}

/* ===================== Printing ===================== */

/**
 * @brief Prints the parsed location map to a log file.
 *
 * @param server Pointer to the Server instance.
 * @param conf The server configuration structure containing the parsed locations.
 */
void	Config::printLogs(Server* server, t_server_conf& conf) {
	std::string	logPath = "./logs/locales";
	std::string	logFile = "./logs/locales/localgen.txt";
	if (createDirectory(logPath.c_str())) {
		std::fstream outfile(logFile.c_str(), std::ios_base::app);
		std::time_t timestamp = std::time(NULL);
		char buff[50];
		std::strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S", std::localtime(&timestamp));
		if (!outfile.fail()) {
			outfile << std::endl;
			outfile << "================================================" << std::endl;
			outfile << "#### SERVER PORT " << server->getListen().port << " " << buff << " ####" << std::endl << std::endl;
			outfile << *server << std::endl;
			outfile << "  ### LOCATIONS ###" << std::endl;
			for (size_t i = 0; i < conf.locationStruct.size(); i++) {
				LocationDir* dir = dynamic_cast<LocationDir*>(conf.locationStruct[i]);
				if (dir) {
					outfile << "Is File: False" << std::endl;
					outfile << "	name: " << dir->name << std::endl;
					outfile << "	redirect: " << dir->redirect << std::endl;
					outfile << "	root: " << dir->root << std::endl;
					outfile << "	alias: " << dir->alias << std::endl;
					outfile << "	allow_methods: ";
					StringVector::iterator it;
					for (it = dir->allow_methods.begin(); it != dir->allow_methods.end(); it++)
						outfile << *it << " ";
					outfile << std::endl;
					for (it = dir->index.begin(); it != dir->index.end(); it++)
						outfile << *it << " ";
					outfile << std::endl;
					for (size_t j = 0; j < dir->files.size(); j++) {
						outfile << "	Script:" << std::endl;
						outfile << "		name: " << dir->files[j]->name << std::endl;
						outfile << "		cgi_pass: " << dir->files[j]->cgi_pass << std::endl;
						outfile << "		allow_methods: ";
						for (it = dir->files[j]->allow_methods.begin(); it != dir->files[j]->allow_methods.end(); it++)
							outfile << *it << " ";
						outfile << std::endl;
					}
					outfile << std::endl;
				}
				else {
					LocationFiles* files = dynamic_cast<LocationFiles*>(conf.locationStruct[i]);
					if (files) {
						StringVector::iterator it;
						outfile << "Is File: True" << std::endl;
						outfile << "	name: " << files->name << std::endl;
						outfile << "	cgi_pass: " << files->cgi_pass << std::endl;
						outfile << "	allow_methods: ";
						for (it = files->allow_methods.begin(); it != files->allow_methods.end(); it++)
							outfile << *it << " ";
						outfile << std::endl;
					}
				}
			}
		}
		outfile.close();
	}
	else throw ConfigFileException("Failed to create logs.");
}


/* ===================== Exceptions ===================== */


Config::ConfigFileException::ConfigFileException(const std::string& error) {
	_errorMsg = "Error: " + error;
}

Config::ConfigFileException::~ConfigFileException() throw() {}


const char *Config::ConfigFileException::what() const throw() {
	return (_errorMsg.c_str());
}
