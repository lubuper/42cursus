# include "../../headers/server/Socket.hpp"

//--------------------------------------Part1-------------------------------

void Socket::createSocket(int domain, int type, int protocol)
{
	this->socketFd_ = socket(domain, type, protocol);
	if (this->socketFd_ == -1)
		throw CreatingSocketException();

}

//--------------------------------------Part2-------------------------------

void Socket::socketBindToPort(int domain, int ipv4Address, int port)
{
	memset((char *)&this->address_, 0, sizeof(this->address_));
	address_.sin_family = domain;
	address_.sin_addr.s_addr = htonl(ipv4Address); // htonl converts a long integer (e.g. address) to a network representation
	address_.sin_port = htons(port); // htons converts a short integer (e.g. port) to a network representation
	if (bind(this->socketFd_, (struct sockaddr *)&this->address_, sizeof(this->address_)) < 0)
		throw BindingSocketException();
}

//--------------------------------------Part3-------------------------------

void Socket::socketListen(int backLog)//tells the socket that it should be capable of accepting incoming connections
{
	if (listen(this->socketFd_, backLog) < 0)
		throw ListeningSocketException();
}

void Socket::socketAccept()
{
	int new_socket;
	int addrlen = sizeof(address_);
	new_socket = accept(this->socketFd_, (struct sockaddr *)&address_, (socklen_t*)&addrlen);
	if (new_socket == -1)
		throw AcceptSocketException();
	acceptedSockets.push_back(new_socket);
}

Socket::Socket()
{
	try
	{
		int domain = AF_INET; // Probably default
		int type = SOCK_STREAM; // Probably default
		int protocol = 0; // Probably default
		int ipv4Address = INADDR_ANY; // Probably default = 0.0.0.0
		int port = 8080; // Not default
		int backLog = 2; // Not default
		createSocket(domain, type, protocol);
		socketBindToPort(domain, ipv4Address, port);
		socketListen(backLog);
		//--------------------------------------Part4-------------------------------
		while(1)
		{
			std::cout << "=== Waiting for new connection ===" << std::endl;
			socketAccept();
			std::string response = "You were accepted on the server!\n";
			send(acceptedSockets.front(), response.c_str(), response.size(), 0);
			while (1)
			{
				char buffer[30000] = {0};
				int bufferRead = read(acceptedSockets.front(), buffer, 30000);
				if (!bufferRead)
					std::cout << "Nothing received." << std::endl;
				if (!strncmp("quit", buffer, strlen("quit")))
				{
					std::string response = "End of communication!\n";
					send(acceptedSockets.front(), response.c_str(), response.size(), 0);
					break ;
				}
				std::cout << "Message received: " << buffer << std::endl;
				std::string response = "Your message was received!\n";
				send(acceptedSockets.front(), response.c_str(), response.size(), 0);
			}
			//--------------------------------------Part5-------------------------------
			close(acceptedSockets.front());
			acceptedSockets.erase(acceptedSockets.begin());
		}
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

Socket& Socket::operator=(const Socket& original)
{
	if (this == &original)
		return *this;
	this->socketFd_ = original.socketFd_;
	return *this;
}

Socket::Socket(const Socket& original)
{
	*this = original;
}


Socket::~Socket()
{
	close(this->socketFd_);
}

int main()
{
	Socket testSocket;
}