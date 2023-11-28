#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>

int	main(void)
{
	std::vector<std::string> list;

	// for (int i = 0; i < 5; i++)
	list.push_back("one");
	list.push_back("two");
	list.push_back("five");
	list.push_back("eight");
	list.push_back("twenty");
	list.push_back("hundred");

	for (int i = 0; i < list.size(); i++)
		std::cout << list[i] << std::endl;
	for (int i = 0; i < list.size(); i++)
		if (list[i] == "five")
			list.erase(list.begin() + i);
	std::cout << std::endl;
	for (int i = 0; i < list.size(); i++)
		std::cout << list[i] << std::endl;
	return (0);
}