/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:53:30 by lde-sous          #+#    #+#             */
/*   Updated: 2024/03/13 15:53:30 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESPONSE_HPP
# define RESPONSE_HPP

# include "../server/Server.hpp"

class Server;
class Request;

class Response
{
	private:
		std::string 				_httpResponse;
		size_t						_indexSize;
		std::vector<std::string>	_indexVector;
		std::string					_rootPath;
		bool						_isAlias;
		bool						_isRedirect;

	public:
		Response();
		Response(const Response& original);
		Response& operator=(const Response& original);
		~Response();
		bool						getRedirectFlag();
		std::string					getHTTPResponse() const;
		void						setHTTPResponse(std::string str);
		void						defaultFlags();
		size_t 						getIndexSize() const;
		std::vector<std::string> 	getIndexVector() const;
		std::string					getRootPath() const;
		void						redirURL(const std::string& url);
		std::string 				itosResponseCode(int code);
		const std::string 			getErrorPage(int errorCode, const t_server_config &serverConf);
		const std::string 			findRoot(Server* server, const std::string& uri);
		LocationDir*				getDir(Server* server, const std::string& name);
		std::string					selectIndexFile(Server* server, int fd, const std::vector<std::string> indexVector, size_t size, const std::string& root, const std::string& uri, bool autoindex, const std::string& possibleIndex);
		int							sendResponse(Server* server, int fd, std::string file, int code);
		int							generateDirListing(Server* server, int fd, std::string location);
		int							sendResponseCGI(int read_fd, int write_fd, int clientSocket);
		class ResponseException : public std::exception
		{
			private:
				std::string _errMessage;
			public:
				ResponseException(const std::string& error);
				~ResponseException() throw();
				virtual const char* what() const throw();
		};
};

std::string responseCode(int code);

#endif
