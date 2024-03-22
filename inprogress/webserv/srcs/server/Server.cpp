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

#include "../../headers/server/Server.hpp"

/* ===================== Orthodox Canonical Form ===================== */

Server::Server() {}

Server::Server(const Server& original) {
	(void)original;
}

Server& Server::operator=(const Server& original) {
	(void)original;
	return (*this);
}

Server::~Server() {
	_body.clear();
}

/* ===================== Constructors ===================== */

Server::Server(const t_listen& listen) : _requestObj(false, false, false) {
	_listen.port = listen.port;
	_listen.host = listen.host;
	_svConf.server_root = "./var/www/html/";
	_svConf.index.push_back("index.htm");
	_svConf.index.push_back("index.html");
	_svConf.index.push_back("index.php");
	_svConf.autoindex = false;
	_svConf.client_max_body_size = 128;
}


/* ===================== Getter Functions ===================== */

long Server::getFD() {
	return _socketfd;
}

int		Server::getConnection(int toFind) {
	std::vector<int>::iterator it = std::find(_connection.begin(), _connection.end(), toFind);
	if (it != _connection.end())
		return *it;
	return -1;
}

const std::vector<std::string>& Server::getBody() const {
	return (_body);
}

std::vector<std::string>& Server::getMutableBody() {
	return (_body);
}

const t_server_conf&	Server::getConf() const {
	return (_svConf);
}

t_server_conf&	Server::getMutableConf() {
	return (_svConf);
}

const t_listen&	Server::getListen() const {
	return (_listen);
}

t_listen&	Server::getMutableListen() {
	return (_listen);
}

Request&	Server::getRequest() {
	return (_requestObj);
}

sockaddr_in*	Server::getSockaddr() {
	return (&_sockaddr);
}

/* ===================== Setter Functions ===================== */

/**
 * @brief Sets the file descriptor of the server.
 *
 * @param fd The file descriptor to set.
 */
void	Server::setFD(long fd) {
	_socketfd = fd;
}

/**
 * @brief Sets the address of the server.
 *
 * This function configures the address family, port, and IP address.
 */
void	Server::setAddr() {
	_sockaddr.sin_family = AF_INET; // Identifier for sockaddr_in by default
	std::cout << "Port: " << _listen.port << std::endl;
	_sockaddr.sin_port = htons(_listen.port);   // listen for t_listen _listen.port //
	std::cout << "Host: " << _listen.host << std::endl;
	_sockaddr.sin_addr.s_addr = INADDR_ANY; /*listen for t_listen _listen.host*/
}

/**
 * @brief Sets the connection descriptor of the server.
 *
 * @param connection The connection descriptor to set.
 */
void	Server::setConnection(int connection) {
	_connection.push_back(connection);
}

/* ===================== Setup Functions ===================== */

/**
 * @brief Sets up the server by creating a socket, binding it to the specified address, and starting to listen for connections.
 *        Also initializes the Request object based on the allowed request methods from the server configuration.
 *
 * @return 0 on success, -1 on failure.
 */
int Server::setup() {
	// Create socket
	setFD(socket(AF_INET, SOCK_STREAM, 0));
	if (getFD() == -1) {
		std::cerr << "Server Creation Error: Could not create socket." << std::endl;
		return -1;
	}
	setAddr();
	if (bind(getFD(), reinterpret_cast<const sockaddr*>(&_sockaddr), sizeof(_sockaddr)) == -1) {
		std::cerr << "Server Creation Error: Could not bind port." << std::endl;
		return -1;
	}
	// Start listening for connections
	if (listen(getFD(), 2) < 0) {
		std::cerr << "Server Creation Error: Could not listen on socket" << std::endl;
		return -1;
	}
	// Initialize Request object based on allowed request methods
	Request requestAux(
		std::find(_svConf.allow_methods.begin(), _svConf.allow_methods.end(), "GET") != _svConf.allow_methods.end(),
		std::find(_svConf.allow_methods.begin(), _svConf.allow_methods.end(), "POST") != _svConf.allow_methods.end(),
		std::find(_svConf.allow_methods.begin(), _svConf.allow_methods.end(), "DELETE") != _svConf.allow_methods.end()
	);
	_requestObj = requestAux;
	return 0;
}

/**
 * @brief Sets the given socket to non-blocking mode.
 *
 * @param socket The socket to set to non-blocking mode.
 * @return 0 on success, -1 on failure.
 */
int Server::setNonBlock(int socket) {
	if (socket < 0) {
		perror("accept");
		return -1;
	}

	// Get current socket flags
	int flags = fcntl(socket, F_GETFL, 0);
	if (flags == -1)
		return -1;

	// Add O_NONBLOCK flag to the socket flags
	flags |= O_NONBLOCK;

	// Set the modified socket flags
	if (fcntl(socket, F_SETFL, flags) == -1)
		return -1;

	return 0;
}


/**
 * @brief Reads data from the client connection and sends a response.
 *
 * @return 0 on success.
 */
int	Server::sender(int socket) {
	char buffer[1024];
	std::string httpResponse;
	std::string request;
	while (true) {
		memset(buffer, 0, sizeof(buffer));
		ssize_t bytesRead = read(getConnection(socket), buffer, sizeof(buffer) - 1);
		if (bytesRead <= 0)
			break ;
		buffer[bytesRead] = '\0';
		request += buffer;
		_requestObj.RequestLogger(request);
		_requestObj.getRequest(request);
		if (request.find("\r\n\r\n") != std::string::npos) {
			std::cout << "breaking request while" << std::endl;
			break ;
		}
	}
	//_requestObj.getResponse(request);
	for (size_t i = 0; i < _svConf.index.size(); ++i) {
		const std::string& filename = _svConf.index[i];
		std::ifstream htmlFile((_svConf.server_root + filename).c_str());
		if (htmlFile.is_open()) {
			_svConf.indexFile = filename;
			htmlFile.close();
			break ;
		}
	}
	if (_svConf.indexFile.empty()) {
		std::ifstream htmlFile((_svConf.server_root + "errors/" + "404.html").c_str());
		if (htmlFile.is_open()) {
			std::stringstream ss;
			ss << htmlFile.rdbuf();
			httpResponse = ss.str();
			htmlFile.close();
			std::stringstream headers;
			headers <<	"HTTP/1.1 200 OK\r\n"
						"Content-Type: text/html\r\n"
						"Content-Length: " << httpResponse.size() << "\r\n\r\n";
			std::string headersStr = headers.str();
			httpResponse = headersStr + httpResponse;
		}
	}	else {
			std::ifstream htmlFile((_svConf.server_root + _svConf.indexFile).c_str());
			if (htmlFile.is_open()) {
				std::stringstream ss;
				ss << htmlFile.rdbuf();
				httpResponse = ss.str();
				htmlFile.close();
				std::stringstream headers;
				headers <<	"HTTP/1.1 200 OK\r\n"
							"Content-Type: text/html\r\n"
							"Content-Length: " << httpResponse.size() << "\r\n\r\n";
				std::string headersStr = headers.str();
				httpResponse = headersStr + httpResponse;
				}
		}
	std::cout << "sending response to " << getListen().port << std::endl;
	send(getConnection(socket), httpResponse.c_str(), httpResponse.size(), 0);
	return 0;
}

int Server::sender(std::string filepath, int code, int socket) {
	char buffer[1024];
	std::string httpResponse;
	std::string request;
	std::ifstream htmlFile((_svConf.server_root + filepath).c_str());
	while (true) {
		memset(buffer, 0, sizeof(buffer));
		ssize_t bytesRead = read(getConnection(socket), buffer, sizeof(buffer) - 1);
		if (bytesRead <= 0)
			break ;
		buffer[bytesRead] = '\0';
		request += buffer;
		_requestObj.RequestLogger(request);
		_requestObj.getRequest(request);
		if (request.find("\r\n\r\n") != std::string::npos) {
			std::cout << "breaking request while" << std::endl;
			break ;
		}
	}
	if (htmlFile.is_open()) {
		std::stringstream ss;
		ss << htmlFile.rdbuf();
		httpResponse = ss.str();
		htmlFile.close();
		std::stringstream headers;
		headers <<	"HTTP/1.1 " << code << " OK\r\n"
					"Content-Type: text/html\r\n"
					"Content-Length: " << httpResponse.size() << "\r\n\r\n";
		std::string headersStr = headers.str();
		httpResponse = headersStr + httpResponse;
	}
	std::cout << "sending response to " << getListen().port << std::endl;
	send(getConnection(socket), httpResponse.c_str(), httpResponse.size(), 0);
	return 0;
}

/**
 * @brief Closes the server's connection and socket descriptors.
 *
 * @return 0 on success.
 */
int		Server::closer(int socket) {
	close(getConnection(socket));
	close(getFD());
	return 0;
}

/* ===================== Body Parsing Functions ===================== */

/**
 * @brief Fills the server's body vector with words from an input string stream.
 *
 * @param iss The input string stream to read from.
 * @return 0 on success.
 */
int	Server::fillBody(std::istringstream& iss) {
	std::string word;
	while (iss >> word)
		getMutableBody().push_back(word); // Accessing the most recently added server
	curlyBracketsCheck();
	return (0);
}

/**
 * @brief Checks the balance of curly brackets in the server's body vector.
 *
 * This function returns 0 if the brackets are balanced, indicating a correct server configuration,
 * and -1 otherwise.
 *
 * @return 0 if the brackets are balanced, -1 otherwise.
 */
int		Server::curlyBracketsCheck()
{
	std::vector<std::string>::iterator itb = _body.begin();
	std::vector<std::string>::iterator ite = _body.end();
	std::vector<std::string> stack;
	if (*itb != "server")
		return (-1);
	while (itb != ite) {
		if (*itb == "{" || *itb == "}")
			stack.push_back(*itb);
		itb++;
	}
	std::vector<std::string>::iterator it;
	if (stack.size() % 2 != 0)
		return (-1);
	for (it = stack.begin(); it != stack.end() && stack.size() > 2; it++) {
		if ((*it).length() != 1)
			return (-1);
		if (*it == "}") {
			if (it == stack.begin() && *it == "}")
				return (-1);
			stack.erase(it);
			stack.erase(it - 1);
			it = stack.begin();
		}
	}
	if ((stack[0] != "{" || stack[1] != "}") && (stack.size() == 2))
		return (-1);
	stack.pop_back();
	stack.pop_back();
	if (!stack.empty())
		return (-1);
	return (0);
}

/* ===================== Exceptions ===================== */
//
// const int Server::ServerCreationException::what() const throw() {
// 	std::cerr << "Server Creation Error: Could not create server." << std::endl;
// 	return -1;
// }

/* ===================== Overloaders ===================== */

std::ostream& operator<<(std::ostream& os, const Server& server) {
	os << "listen: " << server.getListen().host << ":" << server.getListen().port << std::endl;
	os << "server_name: " << server.getConf().server_name.back() << std::endl;;
	os << "root: " << server.getConf().server_root << std::endl;;
	StringVector::const_iterator it;
	for (it = server.getConf().index.begin(); it != server.getConf().index.end(); it++)
		os << "index: " <<  *it << " ";
	os << std::endl;
	os << "autoindex: " << (server.getConf().autoindex ? "on" : "off") << std::endl;
	for (it = server.getConf().allow_methods.begin(); it != server.getConf().allow_methods.end(); it++)
		os << "allow_methods: " << *it << " ";
	os << std::endl;
	std::map<int, std::string>::const_iterator itm;
	os << "error_pages: " << std::endl;
	for (itm = server.getConf().errorPages.begin(); itm != server.getConf().errorPages.end(); itm++)
		os << "	  error: " << itm->first << "    " << itm->second << std::endl;
	os << "client_max_body_size: " << server.getConf().client_max_body_size << std::endl;
	return os;
}
