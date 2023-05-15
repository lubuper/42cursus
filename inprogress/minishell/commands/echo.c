/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:41:29 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/15 19:53:23 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	echo(const char *input)
{
	if (strncmp(input, "echo ", 5) == 0)
    {
		input = input + 5;
		rl_redisplay();
		printf("%s\n", input);
	}
	else if (strcmp(input, "echo") == 0)
		printf("\n");
	else if (strncmp(input, "echo", 4) == 0)
		printf("%s: command not found\n", input);
}