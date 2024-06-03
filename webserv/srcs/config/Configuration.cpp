/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Configuration.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:36:38 by lde-sous          #+#    #+#             */
/*   Updated: 2024/02/05 16:36:38 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/config/Configuration.hpp"

/* ===================== Orthodox Canonical Form ===================== */

Configuration::Configuration()
{
}

Configuration::Configuration(const Configuration& original)
{
	_svBlocks = original._svBlocks;
}

Configuration& Configuration::operator=(const Configuration& original)
{
	_svBlocks = original._svBlocks;
	return (*this);
}

Configuration::~Configuration()
{
	_ports.clear();
}

/* ===================== Constructors ===================== */

Configuration::Configuration(const std::string& path)
{
	try
	{
		std::ifstream file(path.c_str());
		if (!file.is_open())
			throw ConfigurationException("File not accessible.");
		setSvBlocks(file);
	} 
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

/* ===================== Getter Functions ===================== */

std::stack<std::string>& Configuration::getSvBlocks()
{
	return (_svBlocks);
}

/* ===================== Setter Functions ===================== */

struct IsSpace
{
    bool operator()(char c) const
	{
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
void	Configuration::setSvBlocks(std::ifstream& file)
{
	try
	{
		std::string	line, buffer;
		int	flag = 0, openBracket = 0, closeBracket = 0;
		while (std::getline(file, line))
		{
			std::replace_if(line.begin(), line.end(), IsSpace(), ' ');
			if (line.find("server_name") != std::string::npos && flag < 2)
			{
				buffer += line;
				flag++;
			}
			else if (line.find("server") != std::string::npos && flag < 1)
			{
				buffer += line;
				flag++;
			}
			else if (line.find("server") != std::string::npos && flag <= 2)
			{
				openBracket += std::count(buffer.begin(), buffer.end(), '{');
				closeBracket += std::count(buffer.begin(), buffer.end(), '}');
				if (openBracket != closeBracket)
					throw ConfigurationException("Invalid server block.");
				_svBlocks.push(buffer);
				buffer.clear();
				buffer += line;
				flag = 1;
			}
			else
				buffer += line;
		}
		_svBlocks.push(buffer);
		buffer.clear();
		file.close();
	}
	catch (std::exception &e)
	{
    	std::cout << e.what() << std::endl;
		file.close();
	}
}

/* ===================== Configurator Directive Functions ===================== */

/**
 * @brief Parses the configuration to check for correct semicolon placement.
 *
 * @param body The body of the configuration to parse.
 */
void	Configuration::checkSemicolon(std::vector<std::string>& body)
{
	std::vector<std::string>::iterator it;
	std::istringstream keywords(KEYWORDS);
	std::string word;
	if (body.size() > 3 && body[0] == "server" && body[1] == "{" && body[2] == "listen") {
		while (keywords >> word)
			for (it = body.begin() + 3; it != body.end(); it++)
				if (*it == word && (*(it - 1) != ";" && *(it - 1) != "{" && *(it - 1) != "}"))
					throw ConfigurationException("Endline delimiter wrong/missing");
				else if (*it == "}" && (*(it - 1) != ";" && *(it - 1) != "}"))
					throw ConfigurationException("Endline delimiter wrong/missing");
		return ;
	}
	throw ConfigurationException("Server Block not configured correctly.");
}

/**
 * @brief Parses the server name from the configuration body.
 *
 * @param body The body of the configuration to parse.
 * @param conf The server configuration structure to store the parsed server name.
 */
void	Configuration::checkSvName(std::vector<std::string>& body, t_server_config& conf)
{
	std::vector<std::string>::iterator it;
	for (it = body.begin(); it != body.end(); it++)
	{
		if (*it == "location")
		{
			conf.server_name.push_back("_");
			break;
		}
		else if (*it == "server_name")
		{
			it++;
			while (*it != ";") {
				conf.server_name.push_back(*it);
				it++;
			}
			break ;
		}
	}
	if (conf.server_name.size() > 1)
		throw ConfigurationException("Multiple server names defined in server block.");
	else if (conf.server_name.size() < 1)
		throw ConfigurationException("No server name defined in server block.");
}

/**
 * @brief Parses the listen directive from the configuration body, extracting host and port information.
 *
 * This function reads from the input string stream to parse the listen directive and extract the host and port information.
 *
 * @param iss The input string stream to read from.
 * @param listen The structure to store the parsed listen configuration.
 * @throw ConfigurationException If there are errors in the configuration format, such as invalid port numbers or host addresses.
 */
void Configuration::processListen(std::istringstream& iss, t_listen& listen)
{
	std::string word, address, temp_str;
	size_t pos;
	while (iss >> word)
	{
		if (word == "listen")
		{
			iss >> address;
			pos = address.find(":");
			if (pos != std::string::npos) {
				temp_str = address.substr(address.find(":") + 1);
				eraseSemicolon(temp_str);
				!isNumeric(temp_str) ? throw ConfigurationException("Port wrongly formatted => " + temp_str) : 0;
				listen.port = atoi(temp_str.c_str());
				if (listen.port <= 0 || listen.port >= 65535)
					throw ConfigurationException("Port out of range => " + intToStr(listen.port));
				temp_str = address.substr(0, pos);
				if (temp_str == "0.0.0.0")
					listen.host = INADDR_ANY;
				else
				{
					listen.host = convertIP(temp_str);
					!listen.host ? throw ConfigurationException("Couldn't convert host => " + temp_str) : 0;
				}
			}
			else
			{
				listen.host = INADDR_ANY;
				eraseSemicolon(address);
				!isNumeric(address) ? throw ConfigurationException("Port wrongly formatted => " + address) : 0;
				listen.port = atoi(address.c_str());
				if (listen.port <= 0 || listen.port >= 65535)
					throw ConfigurationException("Port out of range => " + intToStr(listen.port));
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
void	Configuration::checkSvRoot(std::vector<std::string>& body, t_server_config& conf)
{
	std::vector<std::string>::iterator it;
	for (it = body.begin(); it != body.end(); it++)
	{
		if (*it == "root")
		{
			it++;
			conf.server_root = *it;
			if (conf.server_root[conf.server_root.length() - 1] != '/')
				conf.server_root += "/";
			break ;
		}
		else if (*it == "location")
			break ;
	}
	std::ifstream file(conf.server_root.c_str());
    !file.good() ? throw ConfigurationException("Path does not exist => " + conf.server_root) : 0;
}

/**
 * @brief Parses the error page directives from the configuration body.
 *
 * @param body The body of the configuration to parse.
 * @param conf The server configuration structure to store the parsed error pages.
 */
void	Configuration::checkErrPage(std::vector<std::string>& body, t_server_config& conf)
{
	int count = 0;
	std::string errorPath;
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
}

/**
 * @brief Parses the index directive from the configuration body.
 *
 * @param body The body of the configuration to parse.
 * @param conf The server configuration structure to store the parsed index files.
 */
void	Configuration::checkIndex(std::vector<std::string>& body, t_server_config& conf)
{
	std::vector<std::string>::iterator it;
	for (it = body.begin(); it != body.end(); it++)
	{
		if (*it == "location")
			break ;
		else if (*it == "index")
		{
			it++;
			conf.index.clear();
			while (*it != ";")
			{
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
void	Configuration::checkMethods(std::vector<std::string>& body, t_server_config& conf)
{
	std::vector<std::string>::iterator it;
	for (it = body.begin(); it != body.end(); it++)
	{
		if (*it == "location")
			throw ConfigurationException("'location' before 'allow_methods' in config file");
		else if (*it == "allow_methods")
		{
			it++;
			while (*it != ";")
			{
				if (*it != "GET" && *it != "POST" && *it != "DELETE")
					throw ConfigurationException("undefined method in config file => " + *it);
				conf.allow_methods.push_back(*it);
				it++;
			}
			break ;
		}
	}
}

/**
 * @brief Parses the client_max_body_size directive from the configuration body.
 *
 * This function iterates through the configuration body to find and parse the client_max_body_size directive,
 * setting the maximum allowed size of the client request body.
 *
 * @param body The vector containing configuration data.
 * @param conf The server configuration structure to store the parsed client_max_body_size value.
 * @throw ConfigurationException If there are errors in the configuration format, such as missing or invalid values.
 */
void	Configuration::checkClientBodySize(std::vector<std::string> &body, t_server_config &conf)
{
	std::vector<std::string>::iterator it;
	for (it = body.begin(); it != body.end(); it++)
	{
		if (*it == "location")
			throw ConfigurationException("'location' before 'client_max_body_size' in config file");
		if (*it == "client_max_body_size")
		{
			it++;
			if (it != body.end() && !isNumeric(*it))
				throw ConfigurationException("invalid client_max_body_size => " + *it);
			int	client_body_size_value = atoi((*it).c_str());
			if (client_body_size_value <= 0 || client_body_size_value > 1024)
				throw ConfigurationException("invalid client_max_body_size => " + intToStr(client_body_size_value));
			conf.client_max_body_size = client_body_size_value;
			return;
		}
	}
}

void Configuration::processLocationDir(std::vector<std::string>::iterator& it, std::vector<std::string>& body, t_server_config& conf)
{
    LocationDir* newDir = new LocationDir;
    newDir->name = *it;
    if (!newDir->name.empty() && newDir->name[newDir->name.size() - 1] == '/')
        newDir->name.erase(newDir->name.size() - 1);
    conf.locationStruct.push_back(newDir);
    it++;
    int bracketCounter = 0;
    while (it != body.end() - 1)
    {
        if (*it == "location" && (*(it + 1)).find("/") != std::string::npos)
        {
            it--;
            break ;
        }
        else if (*it == "{" || *it == "}")
            bracketCounter++;
        else if (*it == "location" && ((*(it + 1)).find("*") != std::string::npos || (*(it + 1)).find(".") != std::string::npos))
            if (*(it + 2) == "{" && (bracketCounter + 1) % 2 != 0)
            {
                it--;
                break ;
            }
        if (*it != "}")
        {
            std::vector<std::string> values = extractValues(it, body, true);
            setKeywords("dir", values, *(conf.locationStruct.back()));
        }
        it++;
    }
    if (it == body.end())
        return;
}

/**
 * @brief Parses the location directives from the configuration body and populates the server configuration structure.
 *
 * This function iterates through the configuration body to find and parse the location directives, creating and populating
 * location structures accordingly in the server configuration. It distinguishes between directory-based and file-based
 * location directives and sets appropriate values.
 *
 * @param server Pointer to the Server object.
 * @param body The vector containing configuration data.
 * @param conf The server configuration structure to populate.
 * @throw ConfigurationException If there are errors in the configuration format or mandatory keywords are missing.
 */
void Configuration::checkLocations(Server* server, std::vector<std::string>& body, t_server_config& conf)
{
	(void)server;
    std::vector<std::string>::iterator it;
    if (checkKeywords(body) == -1)
        throw ConfigurationException("Invalid aliasor methods.");
    for (it = body.begin(); it != body.end(); it++) {
        if (*it == "location") {
            it++;
            if (it != body.end() && (*it).find("/") != std::string::npos)
                processLocationDir(it, body, conf);
            else if ((*it).find("*") != std::string::npos || (*it).find(".") != std::string::npos)
            {
                LocationFiles* newFile = new LocationFiles;
                newFile->name = *it;
                conf.locationStruct.push_back(newFile);
                it++;
                while (it != body.end() && *it != "location")
                {
                    if (*it != "}")
                    {
                        std::vector<std::string> values = extractValues(it, body, true);
                        setKeywords("file", values, *(conf.locationStruct.back()));
                    }
                    it++;
                }
                if (it == body.end())
                {
                    if (newFile->cgi_pass.empty() || !newFile->allow_methods.size())
                    {
                        conf.locationStruct.pop_back();
                        delete newFile;
                    }
                    break ;
                }
                it--;
            }
        }
    }
}

/**
 * @brief Checks for the presence of mandatory keywords in the configuration body.
 *
 * This function iterates through the configuration body to check for the presence of mandatory keywords.
 * Specifically, it checks for the presence of 'alias', 'allow_methods', and 'cgi_pass' directives followed
 * by semicolons. If any of these directives are missing or incorrectly formatted, it returns -1.
 *
 * @param body The vector containing configuration data.
 * @return 0 if all mandatory keywords are present and correctly formatted, -1 otherwise.
 */
int	Configuration::checkKeywords(std::vector<std::string>& body)
{
	std::vector<std::string>::iterator it;
	for (it = body.begin(); it != body.end(); it++)
	{
		if (*it == "alias" && *(it + 1) == ";")
			return (-1);
		else if (*it == "allow_methods")
		{
			it++;
			if (*it == ";")
				return (-1);
			while (*it != ";")
			{
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


int Configuration::setKeywordsDir(std::vector<std::string> values, BaseLocation& strc)
{
    std::istringstream iss(createLocalKeyMap()["dir"]);
    std::string word;
    std::string LocationDir::*data[3] = { &LocationDir::alias, &LocationDir::redirect, &LocationDir::root};
    std::string key[3] = {"alias", "redirect", "root"};
    std::vector<std::string>::iterator values_it = values.begin() + 1;
    if (values.empty())
        return (0);
    LocationDir* dir = dynamic_cast<LocationDir*>(&strc);
    if (dir)
	{
        	while (iss >> word)
			{
				for (int i = 0; i < 3; i++)
				{
					if (values[0] == key[i])
					{
						dir->*data[i] = values[1];
						if (!static_cast<std::string>(dir->root).empty() && !static_cast<std::string>(dir->redirect).empty())
							throw (ConfigurationException("conflituous 'root' and 'redirect' directives in location block"));
						return (0);
					}
				}
				if (values[0] == word && word == "index")
				{
					while (values_it != values.end())
					{
						dir->index.push_back(*values_it);
						values_it++;
					}
				}
				else if (values[0] == word && word == "allow_methods")
				{
					while (values_it != values.end())
					{
						dir->allow_methods.push_back(*values_it);
						values_it++;
					}
				}
				else if (values[0] == word && word == "autoindex")
				{
					if (values.size() == 1)
						dir->autoindex = true;
					else throw ConfigurationException("Autoindex takes no values.");
				}
				else if (values[0] == "location" && ((values[1].find("*") != std::string::npos) || values[1].find(".") != std::string::npos))
				{
					while (iss >> word && *values_it != "}" && values_it != values.end())
					{
						LocationFiles* newFile = new LocationFiles;
						newFile->name = values[1];
						values_it++;
						dir->files.push_back(newFile);
						if (*values_it != "}")
						{
							std::vector<std::string> extract = extractValues(values_it, values, false);
							if (setKeywords("file", extract, *dir->files.back()) == -1)
								dir->files.pop_back();
							return (0);
						}
					}
				}
			}
		}
    return (0);
    }

int Configuration::setKeywordsFile(std::vector<std::string> values, BaseLocation& strc)
{
    std::istringstream iss(createLocalKeyMap()["file"]);
    std::string word;
    std::vector<std::string>::iterator values_it = values.begin() + 1;
    if (values.empty())
        return (0);
    LocationFiles *file = dynamic_cast<LocationFiles*>(&strc);
    if (file) {
       while (iss >> word)
			{
				if (values[0] == word && word == "cgi_pass")
				{
					file->cgi_pass = values[1];
					values_it++;
					if (values_it != values.end())
					{
						values_it++;
						if (*values_it == "allow_methods")
						{
							while (values_it != values.end() && *values_it != ";")
							{
								file->allow_methods.push_back(*values_it);
								values_it++;
							}
						}
					}
				}
				else if (values[0] == word && word == "allow_methods")
				{
					while (values_it != values.end() && *values_it != ";")
					{
						file->allow_methods.push_back(*values_it);
						values_it++;
					}
					while (values_it != values.end())
					{
						if (*values_it == "cgi_pass")
							file->cgi_pass = *(values_it + 1);
						values_it++;
					}
				}
			}
			if (file->cgi_pass.empty() || !file->allow_methods.size())
				return (-1);
		}
    return (0);
}

/**
 * @brief Sets values for keywords in the location structure based on the type of location (directory or file).
 *
 * This function sets values for keywords in the location structure based on the type of location (directory or file).
 * It takes a type parameter specifying whether it's a directory or file, a vector of values containing the keyword
 * values to be set, and a reference to the location structure to populate.
 *
 * @param type The type of location (either "dir" for directory or "file" for file).
 * @param values The vector of values containing keyword values.
 * @param strc The location structure to populate.
 * @return 0 if keyword values are successfully set, -1 otherwise.
 */
int Configuration::setKeywords(std::string type, std::vector<std::string> values, BaseLocation& strc)
{
    if (type == "dir")
        return setKeywordsDir(values, strc);
	else if (type == "file")
        return setKeywordsFile(values, strc);
    return (0);
}

/* ===================== General Checking Functions ===================== */

/**
 * @brief Checks for duplicate occurrences of specific keywords in the configuration body.
 *
 * This function iterates through the configuration body to check for duplicate occurrences
 * of specific keywords. It maintains a count table for each keyword and throws a ConfigurationException
 * if any keyword appears more than once.
 *
 * @param body The vector containing the configuration body.
 * @throws ConfigurationException if any keyword appears more than once.
 */
void	Configuration::checkDoubles(std::vector<std::string>& body)
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
	keywords.insert("autoindex");
	for (std::vector<std::string>::iterator it = body.begin(); it != body.end(); it++)
	{
		if ((*it) == "location" && it + 1 != body.end())
		{
			std::vector<std::string> newBody(it + 1, body.end());
			checkDoubles(newBody);
			break ;
		}
		if (keywords.find(*it) != keywords.end())
			countTable[*it]++;
	}
	for (std::map<std::string, int>::iterator mit = countTable.begin(); mit != countTable.end(); mit++)
		if (mit->second > 1)
			throw ConfigurationException("Duplicate '" + mit->first + "' directive in config file.");
}

/* ===================== Exceptions ===================== */

Configuration::ConfigurationException::ConfigurationException(const std::string& error)
{
	if (!error.empty())
	{
		std::ostringstream err;
		err << BOLD << RED << "Error: " << error << RESET;
		_errMessage = err.str();
	}
}

Configuration::ConfigurationException::~ConfigurationException() throw()
{
}

const char *Configuration::ConfigurationException::what() const throw()
{
	return (_errMessage.c_str());
}
