/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:45:59 by andvieir          #+#    #+#             */
/*   Updated: 2024/02/05 15:45:59 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../headers/server/ServerCluster.hpp"

extern volatile sig_atomic_t gSignalStatus;

/* ===================== Orthodox Canonical Form ===================== */

ServerCluster::ServerCluster() {}

ServerCluster::ServerCluster(const ServerCluster& original) :
	 _servers(original._servers) /*, _config(original._config)*/ {

}

ServerCluster& ServerCluster::operator=(const ServerCluster& original) {
	if (this != &original) {
		_servers = original._servers;
	}
	return *this;
}

ServerCluster::~ServerCluster() {
	for (size_t i = 0; i < _nServ; i++)
		delete _servers[i];
}

/* ===================== Constructors ===================== */

/**
 * @brief Constructs a ServerCluster object and sets up and starts the servers.
 *
 * @param filepath The path to the server configuration file.
 */
ServerCluster::ServerCluster(const std::string& filepath) : _nServ(0), _config(filepath) {
	SetupServers();
	StartServers();
}

/* ===================== Setter functions ===================== */

/**
 * @brief Sets the poll file descriptors for all servers.
 */
void	ServerCluster::setPollFD() {
	_pollfds.reserve(_servers.size());
	std::vector<Server*>::iterator it;
	for (it = _servers.begin(); it != _servers.end(); it++) {
		if (it != _servers.end()) {
			pollfd pfd;
			pfd.fd = (*it)->getFD();
			std::cout << "setted server fd: " << (*it)->getFD() << std::endl;
			pfd.events = POLLIN; //read events
			pfd.revents = 0;
			_pollfds.push_back(pfd);
			_fdToServerMap[(*it)->getFD()] = *it;
		}
	}
}

/* ===================== Getter functions ===================== */

std::vector<Server*>& ServerCluster::getServers() {
	return (_servers);
}

Server* ServerCluster::getServer() {
	return (_servers.back());
}

/* ===================== Server Setup Functions ===================== */

/**
 * @brief Sets up the servers based on configuration.
 *
 * This function parses the server configurations, creates server instances, and sets up their sockets.
 */
void	ServerCluster::SetupServers() {
	t_listen listenStruct;
	while (!_config.getServerBlocks().empty()) {
		try{
			invertStack(_config.getServerBlocks());
			CreateNewServer(listenStruct);
			ParseServer(_servers.back());
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
			ClearServer();
		}
    }
	SetupServerSockets();
	setPollFD();
}

/**
 * @brief Parses server configuration and sets up a server instance.
 *
 * @param server The server instance to parse and set up.
 */
void	ServerCluster::ParseServer(Server* server) {
	verifySemiColon(server);
	callConfigDoubleChecker(server);
	fetchServerName(server);
	fetchServerRoot(server);
	fetchIndex(server);
	fetchMethods(server);
	fetchErrorPage(server);
	fetchClientSize(server);
	fetchLocations(server);
	_config.getServerBlocks().pop();
	_nServ++;
}

/**
 * @brief Creates a new server instance based on configuration.
 *
 * @param listenStruct The listen struct for the server.
 */
void	ServerCluster::CreateNewServer(t_listen& listenStruct) {
	fetchListen(_config.getServerBlocks().top(), listenStruct);
	_servers.push_back(new Server(listenStruct));
	std::istringstream iss(_config.getServerBlocks().top());
	_servers.back()->fillBody(iss);
}

/**
 * @brief Sets up the sockets for all servers.
 */
void	ServerCluster::SetupServerSockets() {
	invertVector(_servers);
	std::cout << "N of servers: " << _servers.size() << std::endl;
	for (size_t i = 0; i < _servers.size(); ++i)
		_servers[i]->setup();
}

/**
 * @brief Clears the server instance.
 */
void	ServerCluster::ClearServer() {
	if (!_servers.empty()) {
		delete _servers.back();
		_servers.pop_back();
	}
	_config.getServerBlocks().pop();
}

void ServerCluster::checkSocketActivity() {
	time_t now = time(NULL);
	for (size_t i = 0; i < _pollfds.size(); ++i) {
		if (_pollfds[i].fd != -1) {
			if ((now - _lastActivityTime[_pollfds[i].fd]) > 5000) {
				close(_pollfds[i].fd);
				_pollfds.erase(_pollfds.begin() + i);
				_lastActivityTime.erase(_lastActivityTime.find(_pollfds[i].fd));
				--i;
			}
		}
	}
}

/* ===================== Config Parser Caller Functions ===================== */


void	ServerCluster::config(std::string file_path) {
	std::cout << file_path << std::endl;
}

void	ServerCluster::verifySemiColon(Server* server) {
	_config.parseSemicolon(server->getMutableBody());
}

void	ServerCluster::callConfigDoubleChecker(Server *server) {
	_config.checkDoubles(server->getMutableBody());
}

void	ServerCluster::fetchServerName(Server* server) {
	_config.parseServerName(server->getMutableBody(), server->getMutableConf());
}

void	ServerCluster::fetchListen(std::string& wordStack, t_listen &listen) {
	std::istringstream iss(wordStack);
	_config.parseListen(iss, listen);
}

void	ServerCluster::fetchServerRoot(Server* server) {
	_config.parseServerRoot(server->getMutableBody(), server->getMutableConf());
}

void ServerCluster::fetchErrorPage(Server* server)
{
	_config.parseErrorPage(server->getMutableBody(), server->getMutableConf());
}

void	ServerCluster::fetchIndex(Server* server) {
	_config.parseIndex(server->getMutableBody(), server->getMutableConf());
}

void	ServerCluster::fetchMethods(Server* server) {
	_config.parseMethods(server->getMutableBody(), server->getMutableConf());
}

void	ServerCluster::fetchClientSize(Server* server) {
	_config.parseClientSize(server->getMutableBody(), server->getMutableConf());
}

void	ServerCluster::fetchLocations(Server* server) {
	_config.parseLocations(server, server->getMutableBody(), server->getMutableConf());
}

/* ===================== Server Execution Functions ===================== */

/**
 * @brief Starts the servers and handles incoming connections.
 *
 * This function continuously polls for events on server sockets and handles incoming connections.
 */
void	ServerCluster::StartServers() {
	while (!gSignalStatus) {
		int numEvents = poll(&_pollfds.front(), _pollfds.size(), -1);
		if (numEvents == -1) {
			std::cerr << "Error in select/poll" << std::endl;
			perror("Select/Poll Error");
			return ;
		}
		if (numEvents == 0) {
			checkSocketActivity();
			continue ;
		}
		for (size_t i = 0; i < _pollfds.size(); ++i) {
			if (_pollfds[i].revents & POLLIN) {
				int fd = _pollfds[i].fd;
				std::map<int, Server*>::iterator it = _fdToServerMap.find(fd);
				if (it != _fdToServerMap.end()) {
					Server* server = it->second;
					size_t addrlen = sizeof(server->getSockaddr());
					int new_socket = accept(server->getFD(), reinterpret_cast<sockaddr*>(server->getSockaddr()), (socklen_t*)&addrlen);
					if (server->setNonBlock(new_socket) == -1)
						continue;
					connectionHandler(new_socket, server);
				}
			}
		}
		// std::cout << "active connections: " << _pollfds.size() << std::endl;
		// std::map<int, Server*>::iterator it;
		// for (it = _fdToServerMap.begin(); it != _fdToServerMap.end(); ++it) {
		// 	std::cout << "FD: " << it->first << " , SERVER: " << it->second.getListen().host
		// }
	}
}

/**
 * @brief Handles an incoming connection on a server.
 *
 * @param new_socket The new socket for the incoming connection.
 * @param server The server instance handling the connection.
 */
void	ServerCluster::connectionHandler(int socket, Server* server) {
	struct pollfd pfd;
	pfd.fd = socket;
	_pollfds.push_back(pfd);
	_fdToServerMap[socket] = server;
	_lastActivityTime[socket] = time(NULL);
	server->setConnection(socket); //
	int events = server->getRequest().updateEvents(server, _pollfds);
	if (events == -1) {
		close(server->getConnection(socket));
		return ;
	}
	if (events & POLLIN)
		server->sender(socket);
	else
		server->sender("errors/40x/405.html", 405, socket);
	std::cout << "connection sent" << std::endl;
	//WE HAVE TO HANDLE THE CLOSE IN A DIFFRENT MANNER
	//close(server->getConnection(socket));
}

/* ===================== Exceptions ===================== */
