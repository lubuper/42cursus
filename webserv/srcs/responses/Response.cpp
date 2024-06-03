/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:56:19 by lde-sous          #+#    #+#             */
/*   Updated: 2024/03/13 15:56:19 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/server/Server.hpp"

/* ===================== Orthodox Canonical Form ===================== */

Response::Response() : _isAlias(false), _isRedirect(false) {}

Response::Response(const Response& original)
{
	_httpResponse = original._httpResponse;
}

Response& Response::operator=(const Response& original)
{
	if (this != &original)
		_httpResponse = original._httpResponse;
	return (*this);
}

Response::~Response() {}

/* ===================== Setter Functions ===================== */

void	Response::setHTTPResponse(std::string str)
{
	_httpResponse = str;
}

void	Response::defaultFlags()
{
	_isAlias = false;
	_isRedirect = false;
}

/* ===================== Getter Functions ===================== */

bool	Response::getRedirectFlag()
{
	return (_isRedirect);
}

std::string	Response::getHTTPResponse() const
{
	return (_httpResponse);
}

size_t	Response::getIndexSize() const
{
	return (_indexSize);
}

std::vector<std::string> Response::getIndexVector() const
{
	return (_indexVector);
}

std::string	Response::getRootPath() const
 {
	return (_rootPath);
}

std::string Response::itosResponseCode(int code)
{
	std::string msg = responseCode(code);
	return msg;
}

/* ===================== Attribute Functions ===================== */

/**
 * @brief Retrieves the error page associated with the given error code from the server configuration.
 *
 * This function searches for the error page corresponding to the provided error code in the server configuration.
 * If the error page is found, it returns the path to the error page file.
 * If the error page is not found, it returns the path to the default error page file.
 *
 * @param errorCode The HTTP error code.
 * @param serverConf The server configuration containing error pages mapping.
 * @return The path to the error page file.
 */
const std::string Response::getErrorPage(int errorCode, const t_server_config &serverConf)
{
	std::map<int, std::string>::const_iterator it = serverConf.errorPages.find(errorCode);
	if (it != serverConf.errorPages.end())
	{
		std::string errorPageDir(it->second);
		size_t pos = errorPageDir.find("0x.html");
		size_t pos2 = errorPageDir.find("xx.html");
		std::string errorCodeStr = intToStr(errorCode);
		if (pos2 != std::string::npos)
		{
			errorCodeStr.erase(0, 1);
			errorPageDir.replace(pos2, 2, errorCodeStr);
		}
		else if (pos != std::string::npos)
			errorPageDir.replace(pos - 1, 3, errorCodeStr);
		std::string errorPage = serverConf.server_root + "errors" + errorPageDir;
		std::ifstream errorFile(errorPage.c_str());
		if (errorFile.is_open())
			return errorPage;
		else
		{
			std::cout << "Error: The error page (" << errorPage  << ") wasn't present in the server files.\nUsing DefaultErrorPage instead." << std::endl;
			return (serverConf.server_root + "errors" + "/DefaultErrorPage.html");
		}
	}
	else
	{
		if (errorCode != 200)
			std::cout << "Error: The error code (" << errorCode << ") wasn't present in the config file.\nUsing DefaultErrorPage instead." << std::endl;
		return (serverConf.server_root + "errors" + "/DefaultErrorPage.html");
	}
}

/**
 * @brief Finds the root directory associated with the requested URI.
 *
 * This function searches for the root directory associated with the requested URI in the server configuration.
 * It iterates through the location blocks to find the appropriate root directory.
 * If the requested URI matches a location block, it returns the corresponding root directory.
 * If no matching location block is found, it returns "404".
 *
 * @param server Pointer to the Server object containing the server configuration.
 * @param uri The requested URI.
 * @return The root directory associated with the requested URI.
 */
const std::string Response::findRoot(Server* server, const std::string& uri)
{
	std::vector<BaseLocation*>::const_iterator it;

	// Set default as 404
	std::string result = "404";
	// If uri is / it means we're at the server root
	if (uri == "/")
		result = "/";

	// Check if uri is present in any other location, even / , because locations have precedence
	for (it = server->getConf().locationStruct.begin(); it != server->getConf().locationStruct.end(); ++it)
	{
		LocationDir* dir = dynamic_cast<LocationDir*>(*it);
		if (dir && dir->name == uri)
		{
			// Check if alias is defined in config file and we've not setted result with the alias previously
			if (!dir->alias.empty() && !_isAlias)
			{
				result = dir->alias;
				_isAlias = true;
				break ;
			}

			// If alias is empty or we checked it previously, now we search if root is defined. If it is, disable alias
			if (!dir->root.empty())
			{
				result = dir->root;
				_isAlias = false;
				break ;
			} // If root is empty then we check redirect
			else if (!dir->redirect.empty())
			{
				result = dir->redirect;
				_isRedirect = true;
				// Update _httpResponse object for redirect
				redirURL(result);
				if (_httpResponse == "400")
					return (_isRedirect = false, "400"); // Turn flag off so we don't trigger a redirect send in the sendResponse function
				break ;
			}
			else {
				return ("404");
			}
		}
	}

	// After receiving the correct path, we manipulate it to have the correct syntax to add to our path
	if (result.find(".") == 0)
	{
		result.erase(0, 1);
		if (result.find("/") == 0)
			result.erase(0, 1);
	}
	else if (result.find("/") == 0)
		result.erase(0, 1);
	return result;
}

/**
 * @brief Retrieves the LocationDir object associated with the given name.
 *
 * This function searches for the LocationDir object with the specified name in the server configuration.
 * It iterates through the location blocks to find the LocationDir object with the matching name.
 * If found, it returns a pointer to the LocationDir object; otherwise, it returns NULL.
 *
 * @param server Pointer to the Server object containing the server configuration.
 * @param name The name of the LocationDir object to retrieve.
 * @return Pointer to the LocationDir object if found; otherwise, NULL.
 */
LocationDir*	Response::getDir(Server *server, const std::string& name)
{
	std::vector<BaseLocation*>::const_iterator it;
	std::string result;
	for (it = server->getConf().locationStruct.begin(); it != server->getConf().locationStruct.end(); ++it)
	{
		LocationDir* dir = dynamic_cast<LocationDir*>(*it);
		if (dir && dir->name == name)
			return dir;
	}
	return NULL;
}

/**
 * @brief Selects the appropriate index file for the requested URI.
 *
 * This function selects the appropriate index file for the requested URI based on the server configuration.
 * It checks if directory listing is enabled and if the requested URI corresponds to a directory.
 * If directory listing is enabled and there are no index files defined, it returns "LIST" indicating directory listing.
 * If the requested URI corresponds to a file directly, it checks for the existence of the file.
 * If the file is found, it returns the file path.
 * If the file is not found, it recursively searches for index files in the directory's root path.
 *
 * @param server Pointer to the Server object containing the server configuration.
 * @param fd File descriptor.
 * @param indexes Vector of index files defined in the server configuration.
 * @param size Size of the indexes vector.
 * @param root Root directory path.
 * @param uri Requested URI.
 * @param autoindex Flag indicating if directory listing is enabled.
 * @param possibleIndex Possible index file.
 * @return The path to the selected index file or directory listing indicator.
 */
std::string	Response::selectIndexFile(Server* server, int fd, const std::vector<std::string> indexVector, size_t size, const std::string& root, const std::string& uri, bool autoindex, const std::string& possibleIndex) {
	std::string newroot;
	std::string locationRoot;

	if (_isRedirect)
		return ("200");
	// Check if directory listing is off and we're trying to access via directory
	LocationDir* dir = getDir(server, uri);
	if(dir)
	{
		if (!autoindex && possibleIndex.empty() && dir->index.size() == 0)
			return ("404");

		// If directory listing is on and there are no index files defined in the location block, list the files present within
		if (autoindex && possibleIndex.empty() && dir->index.size() == 0)
			return ("LIST");
	}
	// In case we're trying to access the file directly, check if it exists, or is accessible
	if (!possibleIndex.empty())
	{

		// If Alias is defined, searches there first
		std::ifstream htmlFile((root + possibleIndex).c_str());
		if (htmlFile.is_open())
		{
			server->getDynamicConfig().indexFile = possibleIndex;
			htmlFile.close();
			return (root);
		}
		// if not found in alias, try root
		else if (_isAlias)
		{
			locationRoot = findRoot(server, uri);
			if (locationRoot == "404" || locationRoot == "400")
				return (locationRoot);
			else if (_isRedirect)
				return ("200"); // Useless return, but it's ok
			// Recursively search for the index file, now in root
			newroot = selectIndexFile(server, fd, indexVector, size, (server->getConf().server_root + locationRoot), uri, autoindex, possibleIndex);
				return (newroot);
		}

	// Try to access via directory when listing is ON
	}
	else
	{

		// Search for the first OK index file provided
		for (size_t i = 0; i < size; i++)
		{
			std::string filename = indexVector[i];
			std::ifstream htmlFile((root + filename).c_str());
			if (htmlFile.is_open())
			{
				server->getDynamicConfig().indexFile = filename;
				htmlFile.close();
				return (root);
			}

			// If we didn't find the index in the alias path, then check the subdirectory's root path
			if (i + 1 >= size && _isAlias)
			{
				// This will fetch the root path since we already have tried alias once
				locationRoot = findRoot(server, uri);
				// We add these checks here because root may also return an error if the file isn't present or we're dealing with a redirect
				if (locationRoot == "404" || locationRoot == "400")
					return (locationRoot);
				else if (_isRedirect)
					return ("REDIRECT"); // Useless return, but it's ok
				// Recursively search for the index file, now in root
				newroot = selectIndexFile(server, fd, indexVector, size, (server->getConf().server_root + locationRoot), uri, autoindex, possibleIndex);
			}
		}
	}

	// Final check if no root is found
	if (newroot.empty())
		return ("404");
	// Will only reach this return if we're recursively search root after alias
	return (newroot);
}

/* ===================== Directory Listing ===================== */

/**
 * @brief Generates a temporary HTML directory listing file and sends it as a response to the client.
 *
 * This function creates a temporary HTML directory listing file containing the contents of the specified directory.
 * It then sends the directory listing file as a response to the client with the provided HTTP status code.
 * After sending the response, it removes the temporary file.
 *
 * @param server Pointer to the Server object.
 * @param fd File descriptor of the client socket.
 * @param location Path of the directory to generate the listing for.
 * @return The number of files listed in the directory.
 */
int	Response::generateDirListing(Server* server, int fd, std::string location)
{
	std::string		filename(".directorylist.html");
	std::string		path("var/www/html/" + filename);
	std::ofstream	tmp(path.c_str());

	// Create temporary HTML directory listing file and count how many files were found in the directory
	int nFiles = 0;
	nFiles = createListHTML(location, tmp);
	tmp.close();

	// Send the list
	sendResponse(server, fd, path, 200);

	// Remove the temp file
	if (std::remove(path.c_str()) != 0)
        std::cout << "Error: Unable to delete file " << path << std::endl;
	return (nFiles);
}

/* ===================== Response Management Functions ===================== */

/**
 * @brief Sends an HTTP response to the client.
 *
 * This function sends an HTTP response to the client with the provided file content and HTTP status code.
 * If the response is a redirect, it sends the redirect response and closes the connection.
 * If the response is not a redirect, it reads the content from the specified file and sends it as the response.
 *
 * @param server Pointer to the Server object.
 * @param fd File descriptor of the client socket.
 * @param file Path of the file containing the response content.
 * @param code HTTP status code.
 */
int	Response::sendResponse(Server* server, int fd, std::string file, int code)
{
	std::string response;
	(void)server;
	// If we're redirecting call _httpResponse from class, send the response and close it. It may be an exterior domain and we have no need to "control" those
	if (_isRedirect && code == 200)
	{
		response = _httpResponse;
		if(send(fd, response.c_str(), response.size(), 0) < 0)
			return -1;
		close(fd);
	}
	else
	{

		// Check if we can open the file, we already did this in selectIndexFile, but it's a good practice
		std::ifstream htmlFile((file).c_str());
		if (htmlFile.is_open())
		{
			// Read the html file and add it to our response headers with the received code and it's appropriate message
			std::stringstream ss;
			ss << htmlFile.rdbuf();
			response = ss.str();
			htmlFile.close();
			std::stringstream headers;
			headers <<	"HTTP/1.1 " << code << " " << itosResponseCode(code) << "\r\n"
						"Content-Type: text/html\r\n"
						"Content-Length: " << response.size() << "\r\n"
						"Cache-Control: no-cache, private \r\n"
						"\r\n";
			std::string headersStr = headers.str();
			response = headersStr + response;
			// Send the response
			if(send(fd, response.c_str(), response.size(), 0) < 0)
				return -1;
		}
		else
		{
			throw ResponseException("HTML file doesn't exist or is inaccessible.");
		}
	}
	gfullRequest.clear();
	return 0;
}

/**
 * @brief Sends an HTTP response containing the content of a CGI script to the client.
 *
 * This function sends an HTTP response to the client with the content received from a CGI script.
 * It reads the content from the specified file descriptor and sends it as the response body.
 *
 * @param read_fd File descriptor for reading from the CGI script.
 * @param write_fd File descriptor for writing to the CGI script.
 * @param clientSocket File descriptor of the client socket.
 */
int	Response::sendResponseCGI(int read_fd, int write_fd, int clientSocket)
{
	// Define a buffer for reading
    const size_t bufferSize = 1024;
    char buffer[bufferSize];

    // Create an empty std::string to hold the content
    std::string content;

    // Read the contents of the file descriptor into the buffer
    ssize_t bytesRead;
    while ((bytesRead = read(read_fd, buffer, bufferSize)) > 0)
	{
        // Append the data read to the std::string object
		std::copy(buffer, buffer + bytesRead, std::back_inserter(content));
		close(write_fd);
    }
	std::stringstream headers;
	headers <<	"HTTP/1.1 " << "200" << " " << itosResponseCode(200) << "\r\n"
					"Content-Type: text/html\r\n"
					"Content-Length: " << content.size() << "\r\n\r\n";
	std::string headersStr = headers.str();
	content = headersStr + content;
	if(send(clientSocket, content.c_str(), content.size(), 0) < 0) // Send to client
		return -1;
	return 0;
}

/**
 * @brief Sets the redirect URL for the response.
 *
 * This function sets the redirect URL for the HTTP response.
 * If the provided URL is a relative path, it adds the server's root URL.
 * If the URL is invalid, it updates the HTTP response to generate a 400 Bad Request error.
 *
 * @param url The URL to redirect to.
 */
void	Response::redirURL(const std::string& url)
{
	std::string rdc;
	std::string url_tmp(url);
	// Checking if we're setting the redirect URL correctly
	// If we find localhost at the beginning of the redirect, then we say the redirect will be either root '/' or a location '/....'
	if (url_tmp.find("localhost") == 0)
	{
		if (url_tmp.find("/") != url_tmp.length() - 1)
			url_tmp += "/";
		rdc = url_tmp.substr(url_tmp.find("/"), std::string::npos);
	}
	else if (url_tmp.find("http") == 0)
		rdc = url_tmp;
	else
	{
		_httpResponse = "400";	// If the previous rules aren't followed we update the response to generate a 400 Bad Request Error
		return ;
	};
	// If succesfull we update the response header with the correct redirect URL
	_httpResponse = "HTTP/1.1 302 Found\r\nLocation: " + rdc + "\r\n\r\n";
}

/**
 * @brief Returns the corresponding status message for an HTTP status code.
 *
 * This function takes an HTTP status code as input and returns the corresponding
 * status message according to the HTTP specification. It covers a wide range
 * of status codes from informational, success, redirection, client error, to server error.
 * If the input status code doesn't match any known codes, it defaults to "OK".
 *
 * @param code The HTTP status code for which to retrieve the status message.
 * @return The corresponding status message for the given status code.
 */
std::string responseCode(int code)
{
	std::string msg;

	switch (code)
	{
		case 100:
			msg = "Continue";
			break;
		case 101:
			msg = "Switching Protocols";
			break;
		case 102:
			msg = "Processing";
			break;
		case 103:
			msg = "Early Hints";
			break;
		case 201:
			msg = "Created";
			break;
		case 202:
			msg = "Accepted";
			break;
		case 203:
			msg = "Non-Authoritative Information";
			break;
		case 204:
			msg = "No Content";
			break;
		case 205:
			msg = "Reset Content";
			break;
		case 206:
			msg = "Partial Content";
			break;
		case 207:
			msg = "Multi-Status";
			break;
		case 208:
			msg = "Already Reported";
			break;
		case 226:
			msg = "IM Used";
			break;
		case 300:
			msg = "Multiple Choices";
			break;
		case 301:
			msg = "Moved Permanently";
			break;
		case 302:
			msg = "Found";
			break;
		case 303:
			msg = "See Other";
			break;
		case 304:
			msg = "Not Modified";
			break;
		case 305:
			msg = "Use Proxy";
			break;
		case 306:
			msg = "unused";
			break;
		case 307:
			msg = "Temporary Redirect";
			break;
		case 308:
			msg = "Permanent Redirect";
			break;
		case 400:
			msg = "Bad Request";
			break;
		case 401:
			msg = "Unauthorized";
			break;
		case 402:
			msg = "Payment Required";
			break;
		case 403:
			msg = "Forbidden";
			break;
		case 404:
			msg = "Not Found";
			break;
		case 405:
			msg = "Method Not Allowed";
			break;
		case 406:
			msg = "Not Acceptable";
			break;
		case 407:
			msg = "Proxy Authentication Required";
			break;
		case 408:
			msg = "Request Timeout";
			break;
		case 409:
			msg = "Conflict";
			break;
		case 410:
			msg = "Gone";
			break;
		case 411:
			msg = "Length Required";
			break;
		case 412:
			msg = "Precondition Failed";
			break;
		case 413:
			msg = "Payload Too Large";
			break;
		case 414:
			msg = "URI Too Long";
			break;
		case 415:
			msg = "Unsupported Media Type";
			break;
		case 416:
			msg = "Range Not Satisfiable";
			break;
		case 417:
			msg = "Expectation Failed";
			break;
		case 418:
			msg = "I'm a teapot";
			break;
		case 421:
			msg = "Misdirected Request";
			break;
		case 422:
			msg = "Unprocessable Content";
			break;
		case 423:
			msg = "Locked";
			break;
		case 424:
			msg = "Failed Dependency";
			break;
		case 425:
			msg = "Too Early";
			break;
		case 426:
			msg = "Upgrade Required";
			break;
		case 428:
			msg = "Precondition Required";
			break;
		case 429:
			msg = "Too Many Requests";
			break;
		case 431:
			msg = "Request Header Fields Too Large";
			break;
		case 451:
			msg = "Unavailable For Legal Reasons";
			break;
		case 500:
			msg = "Internal Server Error";
			break;
		case 501:
			msg = "Not Implemented";
			break;
		case 502:
			msg = "Bad Gateway";
			break;
		case 503:
			msg = "Service Unavailable";
			break;
		case 504:
			msg = "Gateway Timeout";
			break;
		case 505:
			msg = "HTTP Version Not Supported";
			break;
		case 506:
			msg = "Variant Also Negotiates";
			break;
		case 507:
			msg = "Insufficient Storage";
			break;
		case 508:
			msg = "Loop Detected";
			break;
		case 510:
			msg = "Not Extended";
			break;
		case 511:
			msg = "Network Authentication Required";
			break;
		default:
			msg = "OK";
			break;
	}

	return (msg);
}


/* ===================== Exceptions ===================== */

Response::ResponseException::ResponseException(const std::string& error)
{
	std::ostringstream err;
	err << BOLD << RED << "Error: " << error << RESET;
	_errMessage = err.str();
}

Response::ResponseException::~ResponseException() throw() {}

/**
 * @brief Returns the error message associated with this exception.
 *
 * @return The error message as a C-style string.
 */
const char *Response::ResponseException::what() const throw()
{
	return (_errMessage.c_str());
}
