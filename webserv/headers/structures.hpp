/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:21:48 by lde-sous          #+#    #+#             */
/*   Updated: 2024/02/06 15:21:48 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_HPP
# define STRUCTURES_HPP

# include <iostream>
# include <string>

/* ===================== Location Structs ===================== */

/**
 * @brief Base class for location-related configurations.
 *
 * This class serves as the base class for location-related configurations.
 * It defines a virtual destructor to allow polymorphic behavior.
 */
struct BaseLocation
{
	virtual ~BaseLocation()
	{}
};

/**
 * @brief Represents configuration for a file location.
 *
 * This struct represents configuration for a file location in the server block.
 * It inherits from BaseLocation and includes attributes such as the file name,
 * CGI pass information, and allowed HTTP methods.
 */
struct LocationFiles : BaseLocation
{
	std::string					name;
	std::string					cgi_pass;
	std::vector<std::string>				allow_methods;
	LocationFiles()
	{}
	virtual ~LocationFiles()
	{
		allow_methods.clear();
	}
};

/**
 * @brief Represents configuration for a directory location.
 *
 * This struct represents configuration for a directory location in the server block.
 * It inherits from BaseLocation and includes attributes such as the directory name,
 * alias, redirection, root directory, allowed HTTP methods, index files, and a list
 * of nested files configurations.
 */
struct LocationDir : BaseLocation
{
	std::string								name;
	std::string								alias;
	std::string								redirect;
	std::string								root;
	bool									autoindex;
	std::vector<std::string>				allow_methods;
	std::vector<std::string>				index;
	std::vector<LocationFiles*>	files;
		LocationDir() : autoindex(false)
		{}
		virtual ~LocationDir()
		{
			allow_methods.clear();
			index.clear();
			for (size_t i = 0; i < files.size(); i++)
				delete files[i];
		}
};

/* ===================== Server Structs ===================== */

/**
 * @brief Represents configuration for a listen directive.
 *
 * This struct represents configuration for a listen directive in the server block.
 * It includes attributes such as the host and port to listen on.
 */
typedef struct s_listen
{
	unsigned int	host;
	int				port;
} t_listen;

/**
 * @brief Represents the server configuration.
 *
 * This struct represents the server configuration containing various settings such
 * as server name, root directory, index files, allowed HTTP methods, error pages,
 * location configurations, redirection, autoindex setting, and maximum client
 * body size. It also includes the number of location structures configured.
 */
typedef struct s_server_conf
{
	std::vector<std::string>		server_name;
	std::string						server_root;
	std::vector<std::string>		index;
	std::string						indexFile;
	std::vector<std::string>		allow_methods;
	std::map<int, std::string>		errorPages;
	unsigned int					client_max_body_size;
	std::vector<BaseLocation*>	locationStruct;
		s_server_conf() : client_max_body_size(128)
		{}
		~s_server_conf()
		{
			server_name.clear();
			index.clear();
			allow_methods.clear();
			errorPages.clear();
			for (size_t i = 0; i < locationStruct.size(); i++)
				delete locationStruct[i];
		}
} t_server_config;


typedef struct s_cgi_env
{
	std::string auth_mode;
	std::string	content_length;
	std::string	content_type;
	std::string	gateway_interface;
	std::string	path_info;
	std::string	path_translated;
	std::string	query_string;
	std::string	remote_addr;
	std::string	remote_host;
	std::string	remote_ident;
	std::string	remote_user;
	std::string	request_method;
	std::string	script_name;
	std::string	server_name;
	std::string	server_port;
	std::string	server_protocol;
	std::string	server_software;
} t_cgi_env;

#endif
