/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:36:38 by lde-sous          #+#    #+#             */
/*   Updated: 2024/05/17 12:50:24 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/webserv.hpp"
#include "./headers/server/Server.hpp"
#include "./headers/server/Cluster.hpp"

volatile sig_atomic_t gSignalStatus = 0;
Cluster* gServerCluster = NULL;
bool chunky = false;


/**
 * @brief Signal handler function for handling signals in the program.
 *
 * @param signum The signal number.
 */
extern "C" void	signalHandler(int signum) 
{
	std::cout << std::endl;
    if (gServerCluster) 
    {
        std::vector<Server*>::const_iterator it;
        for (it = gServerCluster->getServers().begin(); it != gServerCluster->getServers().end(); ++it)
            close((*it)->getFD());
    }
    (void)signum;
	gSignalStatus = 1;
    const char* loadingIcons[] = {"S", "h", "u", "t", "t", "i", "n", "g", " ", "d", "o", "w", "n", " ", "w", "e", "b", "s", "e", "r", "v", ".", ".", "."};
    const int numIcons = sizeof(loadingIcons) / sizeof(loadingIcons[0]);

    //std::cout << "Closing program safely ";
    std::cout.flush();

    for (int j = 0; j < 24; ++j)
    {
        std::cout << RESET << RED << loadingIcons[j % numIcons] << RESET;
        std::cout.flush();
        usleep(40000);
    }
	usleep(400000);
    std::cout << "\r" << BOLD_GREEN << "Finished \u2713" << RESET;
    std::cout << "                                   \n";
    std::cout << std::endl;
}

void promptIntro(char **envp)
{
	pid_t pid = fork();
	if (pid == 0)
	{
		 char* argv[] = {NULL};
		if (execve("/usr/bin/clear", argv, envp) == -1)
			exit (EXIT_FAILURE);
	}
	waitpid(pid, NULL, 0);
	std::cout << BOLD << RED << "\n";
	usleep(200000);
	std::cout << " █     █░  ▓█████    ▄▄▄▄       ██████   ▓█████    ██▀███     ██▒   █▓\n";
	usleep(37000);
	std::cout << " ▓█░ █ ░█  ░▓█   ▀   ▓█████▄   ▒██    ▒   ▓█   ▀   ▓██ ▒ ██▒  ▓██░   █▒\n";
	usleep(37000);
	std::cout << "▒█░ █ ░█   ▒███     ▒██▒ ▄██░   ▓██▄     ▒███     ▓██ ░▄█ ▒   ▓██  █▒░\n";
	usleep(37000);
	std::cout << "░█░ █ ░█   ▒▓█  ▄   ▒██░█▀      ▒   ██▒  ▒▓█  ▄   ▒██▀▀█▄      ▒██ █░░\n";
	usleep(37000);
	std::cout << "░░██▒██▓   ░▒████▒░  ▓█  ▀█▓  ▒██████▒  ▒░▒████▒  ░██▓ ▒██▒     ▒▀█░  \n";
	usleep(97000);
	std::cout << "░ ▓░▒ ▒    ░░ ▒░ ░  ░▒▓███▀▒▒   ▒▓▒ ▒   ░░░ ▒░ ░  ░ ▒▓ ░▒▓░     ░ ▐░  \n";
	usleep(287000);
	std::cout << "  ▒ ░ ░     ░ ░  ░  ▒░▒   ░ ░   ░▒  ░   ░ ░ ░  ░    ░▒ ░ ▒░     ░ ░░  \n"; 
	usleep(387000);
	std::cout << "  ░   ░       ░      ░    ░ ░    ░  ░       ░       ░░   ░        ░░  \n";
	usleep(497000);
	std::cout << "    ░         ░  ░   ░              ░       ░  ░     ░             ░  \n";
	usleep(597000);
	std::cout << "  ░            ░  ░   ░    ░                  ░        ░           ░    \n";
	std::cout << std::endl;
	std::cout << "                       ░                                 ░" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}

int		main(int ac, char **av, char **envp)
{
    promptIntro(envp);
    std::string filename;
    signal(SIGPIPE, SIG_IGN);
    if (ac != 2)
        std::cout << RED << "Error: " << RESET << "Usage: ./webserv [configuration file]" << std::endl;
    else
	{
        signal(SIGINT, signalHandler);
        Cluster cluster(av[1]);
        gServerCluster = &cluster;
        cluster.startServers();
    }
	return (EXIT_SUCCESS);
}
