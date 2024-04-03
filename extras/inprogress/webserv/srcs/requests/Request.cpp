/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:04:14 by andvieir          #+#    #+#             */
/*   Updated: 2024/03/06 14:04:14 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/server/Server.hpp"

/* ===================== Orthodox Canonical Form ===================== */

Request::Request() {}

Request::Request(const Request& original) {
	(void)original;
}

Request& Request::operator=(const Request& original) {
	if (this != &original) {
		_GETAllowed = original._GETAllowed;
		_POSTAllowed = original._POSTAllowed;
		_DELETEAllowed = original._DELETEAllowed;
	}
	return (*this);
}

Request::~Request() {}

/* ===================== Constructors ===================== */

/**
 * @brief Constructor for the Request class.
 *        Initializes the allowed request methods flags with the provided values.
 *
 * @param GET    Flag indicating whether the GET method is allowed.
 * @param POST   Flag indicating whether the POST method is allowed.
 * @param DELETE Flag indicating whether the DELETE method is allowed.
 */
Request::Request(bool GET, bool POST, bool DELETE) :
	_GETAllowed(GET), _POSTAllowed(POST), _DELETEAllowed(DELETE), _userMethodisAllowed(false) {}

/* ===================== Getter Functions ===================== */

bool	Request::isGETAllowed() const {
	return (_GETAllowed);
}

bool	Request::isPOSTAllowed() const {
	return (_POSTAllowed);
}

bool	Request::isDELETEAllowed() const {
	return (_DELETEAllowed);
}

std::string	Request::getReqMethod() const {
	return (_methods);
}

std::string	Request::getReqUri() const {
	return(_uri);
}

std::string	Request::getReqHVersion() const {
	return (_httpVersion);
}

/**
 * @brief Extracts and returns the value of a specified header from an HTTP request string.
 *
 * @param request    The HTTP request string.
 * @param headerName The name of the header to extract the value for.
 * @return The value of the specified header, or an empty string if the header is not found.
 */
std::string Request::getHeaderValue(const std::string& request, const std::string& headerName) {
	std::istringstream requestStream(request);
	std::string line;
	while (std::getline(requestStream, line)) {
		std::istringstream lineStream(line);
		std::string name;
		std::getline(lineStream, name, ':');
		if (name == headerName) {
			std::string value;
			std::getline(lineStream, value);
			return value;
		}
	}
	return ("");
}

bool Request::validateRequestMethod(const std::string& method) {
	if ((method == "GET" && _GETAllowed) || (method == "POST" && _POSTAllowed) || (method == "DELETE" && _DELETEAllowed)) {
		_userMethodisAllowed = true;
		return true;
	}
	return false;
}

void Request::getRequest(const std::string& request) {
	size_t methodFind = request.find(' ');
	std::string method = request.substr(0, methodFind); //Expected to be the method GET POST or DELETE

	if (validateRequestMethod(method))
		std::cout << "Method is: " << method << std::endl;
	else
		std::cout << "Method is not defined in our list: " << method << std::endl;

	std::string restOfMethodLine = request.substr(methodFind + 1);

	size_t uriFind = restOfMethodLine.find(' ');
	std::string uri = restOfMethodLine.substr(0, uriFind);

	std::cout << "Request location is: " << uri << std::endl;

	size_t hostFind = request.find("Host:");
	size_t hostEnd = request.find("\r\n", hostFind);

	std::string host = request.substr(hostFind, hostEnd);
	std::cout << "Host is: " << host << std::endl;
}

/* ===================== Event Management Functions ===================== */

/**
 * @brief Updates the events field of the pollfd structure for the given server based on its allowed request methods.
 *
 * @param server The server whose pollfd structure needs to be updated.
 * @param polls  The vector of pollfd structures to search and update.
 */
int	Request::updateEvents(Server* server, std::vector<pollfd> polls) {
	if (server == NULL)
		return -1;

	int events = 0;
	if (server->getRequest().isGETAllowed())
		events |= POLLIN;
	if (server->getRequest().isPOSTAllowed() || server->getRequest().isDELETEAllowed())
		events |= POLLOUT;

	std::vector<pollfd>::iterator it;
	for (it = polls.begin(); it != polls.end(); it++) {
		if (it != polls.end() && it->fd == server->getConnection(it->fd) ) {
			// Update the events field of the pollfd structure
			it->events = events;
			return events;
		}
	}
	return -1;
}

/* ===================== Logger Functions ===================== */

/**
 * @brief Logs an HTTP request to a file along with a timestamp.
 *
 * @param request The HTTP request string to log.
 * @throw RequestFileException If an error occurs while creating or writing to the log file.
 */
void	Request::RequestLogger(std::string request) {
	if (createDirectory("./logs/requests")) {
		std::fstream outfile("./logs/requests/requestlogs.log", std::ios_base::app);
		std::time_t timestamp = std::time(NULL);
		char buff[50];
		std::strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S", std::localtime(&timestamp));
		if (!outfile.fail()) {
			outfile << std::endl;
			outfile << "====================== " << buff << " =======================" << std::endl;
			outfile << request << std::endl;
		}
		outfile.close();
	}
	else throw RequestFileException("Failed to create request logs.");
}

/* ===================== Exceptions ===================== */

/**
 * @brief Constructs a RequestFileException object with the given error message.
 *
 * @param error The error message to include in the exception.
 */
Request::RequestFileException::RequestFileException(const std::string& error) {
	_errorMsg = "Error: " + error;
}

Request::RequestFileException::~RequestFileException() throw() {}

/**
 * @brief Returns the error message associated with this exception.
 *
 * @return The error message as a C-style string.
 */
const char *Request::RequestFileException::what() const throw() {
	return (_errorMsg.c_str());
}
