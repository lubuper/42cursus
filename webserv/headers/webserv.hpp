/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneous.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:15:11 by lde-sous          #+#    #+#             */
/*   Updated: 2024/02/06 16:15:11 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HPP
# define WEBSERV_HPP

# pragma once

/* ===================== Common ===================== */

# include <string>
# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <unistd.h>
# include <csignal>
# include <sys/wait.h>
# include <sys/stat.h>
# include <ctime>
# include <cstdio>
# include <fcntl.h>
# include <cstring>
# include <cstdio>
# include <typeinfo>
# include <dirent.h>

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
# include <sys/epoll.h>
# include <sys/select.h>
# include <netdb.h>

/* ===================== Colors ===================== */

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[93m"
# define RESET "\033[0m"
# define CYAN "\033[36m"
# define MAGENTA "\033[35m"
# define BLUE "\033[34m"
# define WHITE "\033[37m"
# define BLACK "\033[30m"
# define BOLD_RED "\033[1;31m"
# define BOLD_GREEN "\033[1;32m"
# define BOLD_YELLOW "\033[1;33m"
# define BOLD_MAGENTA "\033[1;35m"
# define BOLD_BLUE "\033[1;34m"
# define BOLD_CYAN "\033[1;36m"
# define BOLD_WHITE "\033[1;37m"
# define BOLD_BLACK "\033[1;30m"
# define UNDERLINE "\033[4m"
# define REVERSE "\033[7m"
# define BOLD "\033[1m"
# define BLINK "\033[5m"
# define CONCEAL "\033[8m"
# define CROSSED_OUT "\033[9m"
# define FRAMED "\033[51m"
# define ENCIRCLED "\033[52m"
# define OVERLINED "\033[53m"
# define NOT_FRAMED_OR_ENCIRCLED "\033[54m"

/* ===================== String Macros ===================== */

# define KEYWORDS "listen server_name root index allow_methods error_page client_max_body_size cgi_pass redirect autoindex alias"
# define MAX_EVENT_BUFFER 1
# define ACTIVITY_TIMEOUT 10

/* ===================== Global Variable ===================== */

extern std::string gfullRequest;

/* ===================== Misc ===================== */

bool			isNumeric(std::string str);
void			eraseSemicolon(std::string &str);
extern "C" void	signalHandler(int signum);
unsigned int    convertIP(const std::string& addr);
std::string     ipToStr(unsigned int addr);
std::vector<std::string> 	extractValues(std::vector<std::string>::iterator& it, const std::vector<std::string>& body, bool IsDir);
bool			createDirectory(const char *path);
std::map<std::string, std::string> 	createLocalKeyMap();
int             createListHTML(std::string location, std::ofstream& file);
std::string     intToStr(int number);
void slowCout(const std::string& str);

template <typename T> void	invertStack(std::stack<T>& original);
template <typename T> void	invertVector(std::vector<T>& original);

# include "../srcs/Utils.tpp"

#endif
