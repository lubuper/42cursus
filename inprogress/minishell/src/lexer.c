/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/15 19:53:11 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
    The command function handles basic command recognition
    and execution based on the input string, providing
    feedback or return values accordingly.
*/

void command(const char *input)
{
    if (strcmp(input, "pwd") == 0)
        printf("pwd\n");
    else if (strcmp(input, "cd") == 0)
        printf("cd\n");
    else if ((strncmp(input, "echo ", 5) == 0) || (strncmp(input, "echo", 4) == 0))
        echo(input);
    else if (strcmp(input, "export") == 0)
        printf("export\n");
    else if (strcmp(input, "unset") == 0)
        printf("unset\n");
    else if (strcmp(input, "env") == 0)
        printf("env\n");
    else if (strcmp(input, "exit") == 0)
        return ;
    else
        printf("%s: command not found\n", input);
}