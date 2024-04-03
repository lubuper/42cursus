#include <ifstream>
#include <iostream>


int main() {
std::ifstream file("nginx.conf");

	if (file.find("\r"))
		std::cout << "found" << std::endl;
}
