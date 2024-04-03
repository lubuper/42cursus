#include <sys/types.h> // Socket
#include <sys/socket.h> // Socket

#include <string.h> // Strerror
#include <iostream> // Output and input stream


int main()
{
	int server_fd = socket(AF_INET, SOCK_STREAM, 0); //AF_INET Stands for IPv4 Protocols | SOCK_STREAM Stands for TCP Protocol (2 WAY Communication)
	if (server_fd == -1)
		std::cout << "Couldn create socket because: " << strerror(errno) << std::endl;
}
