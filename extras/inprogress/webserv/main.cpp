/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:36:38 by lde-sous          #+#    #+#             */
/*   Updated: 2024/02/06 15:36:38 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "headers/config/confParser.hpp"
// #include "headers/server/ServerCluster.hpp"
#include "./headers/webserv.hpp"
#include "./headers/server/Server.hpp"
#include "./headers/server/ServerCluster.hpp"

//ServerCluster* GlobalServerPtr = NULL;

volatile sig_atomic_t gSignalStatus = 0;

/**
 * @brief Signal handler function for handling signals in the program.
 *
 * @param signum The signal number.
 */
extern "C" void	signalHandler(int signum) {
	std::cerr << std::endl << "Closing Program Safely";
	std::cerr << ".";
	std::cerr << ".";
	std::cerr << ".";
    (void)signum;
	gSignalStatus = 1;
}

int		main(int ac, char **av)
{

    std::string filename;
    signal(SIGINT, signalHandler);
    signal(SIGPIPE, SIG_IGN);
    if (ac != 2) {
        while(filename.empty()) {
            std::cout << "Please input file path and name > ";
            if (!std::getline(std::cin, filename)) {
                std::cerr << "EXIT\r\n";
                exit(EXIT_FAILURE);
            }
        }
        ServerCluster cluster(filename);
    }
    else ServerCluster cluster(av[1]);
	return (EXIT_SUCCESS);
}
