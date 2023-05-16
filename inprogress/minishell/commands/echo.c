/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:41:29 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/16 22:26:50 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*trim_back(const char *input)
{
	char *result;
	int i;
	int j;
	
	i = 0;
	while (input[i] == ' ')
		i++;
	result = malloc(sizeof(char) * (ft_strlen(input) - i) + 1);
	if (!result)
		return (NULL);
	j = 0;
	while (input[i])
	{
		result[j] = input[i];
		j++;
		i++;
	}
	result[j] = '\0';
	return (result);
}

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
}