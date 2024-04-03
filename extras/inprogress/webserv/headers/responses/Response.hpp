/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:53:30 by andvieir          #+#    #+#             */
/*   Updated: 2024/03/13 15:53:30 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESPONSE_HPP
# define RESPONSE_HPP

# include "../server/Server.hpp"

class Server;
class Request;

class Response {
	private:
		std::string _httpResponse;
	public:
		Response();
		Response(const Response& original);
		Response& operator=(const Response& original);
		~Response();

		std::string	generateResponse(Server* server, const std::string& request);
};

#endif
