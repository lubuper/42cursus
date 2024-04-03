/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:56:19 by andvieir          #+#    #+#             */
/*   Updated: 2024/03/13 15:56:19 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/server/Server.hpp"

Response::Response() {}

Response::Response(const Response& original) {
	_httpResponse = original._httpResponse;
}

Response& Response::operator=(const Response& original) {
	if (this != &original)
		_httpResponse = original._httpResponse;
	return (*this);
}

Response::~Response() {}


std::string Response::generateResponse(Server* server, const std::string& request) {
	(void)server;
	(void)request;
	// Request& reqObj = server->getRequest();
	// if (request.find("HTTP/1.1") == std::string::npos)
	// 	return ("");
	// // std::string acceptLanguage = request.getHeaderValue(request, "Accept-Language");
	// _httpResponse += "HTTP/1.1 200 OK\r\n";
	// _httpResponse += "Content-Type: " + reqObj.getHeaderValue(request, "Content-Type") + "\r\n";
	// _httpResponse += "Server: " + server->getConf()->server_name + "\r\n";
	// _httpResponse += "Index: " + server->getConf()->indexFile + "\r\n";

	return NULL;
}
