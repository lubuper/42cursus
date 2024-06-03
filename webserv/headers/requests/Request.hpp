/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Requests.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:15:10 by lde-sous          #+#    #+#             */
/*   Updated: 2024/03/05 15:15:10 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REQUEST_HPP
# define REQUEST_HPP

# pragma once
# include "../webserv.hpp"
# include "../server/Server.hpp"

class Server;

class Request
{

	private:		
		std::string _method;
		std::string _uri;
		std::string _httpVersion;
		std::string	_firstLine;
		std::string _fullRequest;
		std::string _requestHeader;
		std::string _requestBody;
		std::string _contentType;
		std::string _contentValue;
		std::string _boundary;
		std::string _contentLength;
		std::string _file;
		std::string _host;
		bool		_isPageOK;

	public:
		bool		_isChunked;
		bool		_isRequestComplete;
		Request();
		Request(const Request& original);
		Request& operator=(const Request& original);
		~Request();
		int			fillHeader(int socket);
		int			fillAttributes(const std::string& request);
		void		parseRequest();
		std::string trimValue(std::string toBeTrimmed);
		std::string parseFilename(std::string ClearDisposition);
		void 		parseContentType(std::string ContentType);
		std::string bodyParser();
		std::string getHeader(const std::string& headerName);
		bool 		checkMethod(Server* server);
		std::string	getMethod() const;
		std::string	getURI() const;
		std::string	getHTTPVersion() const;
		std::string	getContentLen() const;
		std::string	getContentType() const;
		std::string	getFilename() const;
		std::string	getBody() const;
		std::string	getHost() const;
		double		getContentLength();
		int			ConfigureRequest(Server *server);
		void		chunkDecoder();
		void		reqLogger(std::string request);
		int			checkClientBodySize(Server* server);
		
		class RequestException : public std::exception
		{
			private:
				std::string _errMessage;
			public:
				RequestException(const std::string& error);
				~RequestException() throw();
				virtual const char* what() const throw();
		};
};


#endif
