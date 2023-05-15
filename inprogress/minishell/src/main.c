/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/05/15 19:53:16 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void handle_interrupt(int signal)
{
    if (signal == SIGINT)
    {
        printf("\n");           // Print a newline to start a new line after the prompt
        rl_replace_line("", 0); // Clear the current input line
        rl_on_new_line();       // Move to a new line
        rl_redisplay();         // Redisplay the prompt
    }
}

void    set_signals(void)
{
    // Set up signal handlers
    signal(SIGINT, handle_interrupt);   // Handle Ctrl+C
    signal(SIGQUIT, SIG_IGN);           // Ignore Ctrl+"\"
    signal(SIGTSTP, SIG_IGN);           // Ignore Ctrl+Z
}

int	main(int ac, char **av, char **envp)
{
	char	*str;
	
	(void)ac; 
	(void)av; 
	(void)envp;
	str = av[1];

	rl_clear_history();
    // Load the command history from a file
    set_signals();
    //read_history("minishell_history.txt");
	while (1)
	{
		// Read the command from the user
        str = readline("\033[0;32mminishell$\033[0m ");
        if (str == NULL)
        {
			rl_clear_history();
            break;
        }
		command(str);
        // Add the command to the history
        add_history(str);

        // Check if the comsmand is "exit"
        if (strcmp(str, "exit") == 0)
            break;

        // Save the command history to a file
        //write_history("minishell_history.txt");
        free(str);
	}
	return (0);
}