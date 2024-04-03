/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneous.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:15:11 by andvieir          #+#    #+#             */
/*   Updated: 2024/02/06 16:15:11 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HPP
# define WEBSERV_HPP

# pragma once

/* ===================== Common ===================== */

# include <string>
# include <iostream>
# include <cstdlib>
# include <unistd.h>
# include <csignal>
# include <sys/wait.h>
# include <sys/stat.h>
# include <ctime>
# include <stdio.h>
# include <fcntl.h>
# include <cstring>
# include <cstdio>

/* ===================== Containers ===================== */

# include <vector>
# include <stack>
# include <map>
# include <algorithm>
# include <set>

/* ===================== Streams ===================== */

# include <fstream>
# include <sstream>

/* ===================== Web Servers ===================== */

# include <netinet/in.h>
# include <arpa/inet.h>
# include <sys/socket.h>
# include <poll.h>
# include <sys/select.h>
# include <netdb.h>

/* ===================== Colors ===================== */

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define RESET "\033[0m"

/* ===================== String Macros ===================== */

# define KEYWORDS "listen server_name root index allow_methods error_page client_max_body_size cgi_pass redirect autoindex alias"


/* ===================== Typedefs ===================== */

typedef std::map<std::string, std::string> Map;
typedef std::vector<std::string> StringVector;
typedef bool IsFile;
//typedef std::map<std::string, StringVector > InnerLocationMap;
//typedef std::map<IsFile, InnerLocationMap> LocationMap;

/* ===================== Miscellanious ===================== */

bool			isNumeric(std::string str);
void			removeSemiColon(std::string &str);
extern "C" void	signalHandler(int signum);
void			checkSocketActivity(std::vector<int>&sockets);

unsigned int    convertAddr(const std::string& addr);

StringVector 	extractValues(StringVector::iterator& it, const StringVector& body, bool IsDir);

bool			createDirectory(const char *path);
Map 			createLocalKeyMap();

std::string     intToStr(int number);

template <typename T>
void	invertStack(std::stack<T>& original);

template <typename T>
void	invertVector(std::vector<T>& original);

void	debugTimeStamp();

# include "../srcs/Utils.tpp"

#endif
