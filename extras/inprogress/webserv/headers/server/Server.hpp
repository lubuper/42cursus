/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:36:38 by andvieir          #+#    #+#             */
/*   Updated: 2024/02/05 14:36:38 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# pragma once
# include "../webserv.hpp"
# include "../structures.hpp"
# include "../requests/Request.hpp"
# include "../responses/Response.hpp"

class Request;
class Response;

/**
 * @brief Class that manages a server for handling connections.
 *
 * The Server class encapsulates the functionality for setting up and managing
 * a server that handles connections. It provides methods for retrieving and
 * setting the socket descriptor and sockaddr_in structure.
 *
 * @note This class follows the Singleton pattern, ensuring only one instance
 * of the server is created.
 *
 * @param _socketfd
 *   The socket descriptor used to identify the server's endpoint for incoming
 *   connections.
 *
 * @param _sockaddr
 *   The sockaddr_in structure, which contains basic structures for all syscalls
 *   and functions that deal with internet addresses. It represents the address
 *   and port information of the server.
 */
class Server {

	private:
		Server();
		Server(const Server& original);
		Server& operator=(const Server& original);
		long						_socketfd;
		sockaddr_in					_sockaddr;
		t_listen					_listen;
		std::vector<int>			_connection;
		t_server_conf				_svConf;
		std::vector<std::string>	_body;
		Request						_requestObj;
		Response					_responseObj;

	public:
		Server(const t_listen& listen);
		virtual ~Server();

		long	getFD();
		// sockaddr_in getAddr();
		int		getConnection(int toFind);
		const std::vector<std::string>& getBody() const;
		std::vector<std::string>& getMutableBody();
		const t_server_conf&	getConf() const;
		t_server_conf&	getMutableConf() ;
		const t_listen&	getListen() const;
		t_listen&	getMutableListen() ;
		Request&	getRequest();
		sockaddr_in*	getSockaddr();

		void	setFD(long fd);
		void	setAddr();
		//void	setAddr(struct hostent* serverHost);
		void	setConnection(int connection);
		int		setNonBlock(int socket);

		int		setup();
		int		closer(int socket);
		//int		accept(Server* server, std::vector<struct pollfd>& _pollfds, std::map<int, Server*>& _fdToServerMap, size_t& addrlen);
		int		sender(int socket);
		int 	sender(std::string filepath, int code, int socket);

		int		curlyBracketsCheck();
		int		fillBody(std::istringstream& iss);
		// class ServerCreationException : public std::exception {
		// 	public:
		// 		virtual const int what() const throw();
		// };
};

std::ostream& operator<<(std::ostream& os, const Server& server);

#endif
