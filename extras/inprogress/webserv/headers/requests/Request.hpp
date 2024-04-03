/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Requests.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:15:10 by andvieir          #+#    #+#             */
/*   Updated: 2024/03/05 15:15:10 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REQUEST_HPP
# define REQUEST_HPP

# pragma once
# include "../webserv.hpp"
# include "../server/Server.hpp"

class Server;

class Request {

	private:
		Request(const Request& original);
		/*bools that save server's allowed methods*/
		bool	_GETAllowed;
		bool	_POSTAllowed;
		bool	_DELETEAllowed;
		bool	_userMethodisAllowed;
		std::string _methods;
		std::string _uri;
		std::string _httpVersion;


	public:
		Request();
		Request(bool GET, bool POST, bool DELETE);
		Request& operator=(const Request& original);
		~Request();
		bool	isGETAllowed() const;
		bool	isPOSTAllowed() const;
		bool	isDELETEAllowed() const;

		std::string getHeaderValue(const std::string& request, const std::string& headerName);
		bool validateRequestMethod(const std::string& method);
		void getRequest(const std::string& request);
		std::string	getReqMethod() const;
		std::string	getReqUri() const;
		std::string	getReqHVersion() const;

		int		updateEvents(Server* server, std::vector<pollfd> polls);
		void	RequestLogger(std::string request);
		class RequestFileException : public std::exception {
			private:
				std::string _errorMsg;
			public:
				RequestFileException(const std::string& error);
				~RequestFileException() throw();
				virtual const char* what() const throw();
		};
};

#endif
