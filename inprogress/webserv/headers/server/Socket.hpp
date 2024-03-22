#ifndef SOCKET_HPP
# define SOCKET_HPP

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

#include <sstream>

/* Error handling */
#include <stdexcept>
#include <cerrno>
#include <cstring>

/* Temporary for printing */
#include <iostream>

#include <vector>

#define BACKLOG 10 // Number of max request on the server

class Socket {
private:
	/* Socket file descriptor */
	int socketFd_;
	std::vector<int> acceptedSockets;
	/* Address struct used for socketListen()*/
	struct sockaddr_in address_;
	/**
	 * @brief Create a socket.
	 * @param domain The domain argument specifies a communication domain.
	 * @param type The  socket  has  the indicated type, which specifies the communication
       * semantics.
	 * @param protocol The  protocol  specifies  a  particular  protocol  to  be used with the
       * socket.
	*/
	void createSocket(int domain, int type, int protocol);
	/**
	 * @brief Make a socket listen to a specific port.
	 * @param domain The domain argument specifies a communication domain.
	 * @param ipv4Address IPv4 Address for the socket to listen.
	 * @param port The port for the socket to listen to.
	*/
	void socketBindToPort(int domain, int ipv4Address, int port);
	/**
	 * @brief Marks  the  socket referred to by sockfd as a passive socket,
       * that is, as a socket that will be used to  accept  incoming  connection
       * requests using.
	 * @param backlog  Marks  the  socket referred to by socketFd_ as a passive socket,
       * that is, as a socket that will be used to  accept  incoming  connection
       * requests using.
	*/
	void socketListen(int backLog);
	/**
	 * @brief Uses system  call with connection-based socket types It extracts the
	 * first  connection  request  on  the  queue  of pending connections for the 
	 * listening socket, sockfd, creates a new connected socket.
	 * @return On  success,  these  system  calls return a file descriptor for the
       *  accepted socket (a nonnegative integer).  On error, call for exception.
	*/
	void socketAccept();
public:
	/**
	 * @brief Default constructor for socket
	*/
	Socket();
	/**
	 * @brief Copy constructor for socket
	*/
	Socket(const Socket& original);
	/**
	 * @brief Copy assigment operator for socket
	*/
	Socket& operator=(const Socket& original);
	/**
	 * @brief Destructor for socket
	*/
	~Socket();
	class CreatingSocketException : public std::exception {
		public:
			virtual const char *what() const throw(){return "Error Creating Socket: ";}
  	};
	class BindingSocketException : public std::exception {
		public:
			virtual const char *what() const throw(){return "Error Binding Socket: ";}
  	};
	class ListeningSocketException : public std::exception {
		public:
			virtual const char *what() const throw(){return "Error Listening Socket: ";}
	};
	class AcceptSocketException : public std::exception {
		public:
			virtual const char *what() const throw(){return "Error creating New Socket: ";}
	};
};	
#endif
