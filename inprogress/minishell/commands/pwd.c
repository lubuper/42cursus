/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:51:22 by alexfern          #+#    #+#             */
/*   Updated: 2023/05/16 19:27:21 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* char    *white_sp_rm(const char *str)
{
    char    *output;
    int     i;
    int     j;
	
    output = malloc(sizeof(char) * 4);
    if (!output)
        return (0);
    i = 0;
    j = 0;
    while (str[i])
    {
        if (str[i] == ' ')
            i++;
        else
        {
            output[j] = str[i];
            j++;
        }
        i++;
    }
        output[3] = 0;
    return (output);
} */

int pwd(void)
{
	char	pwd[1024];

	if (getcwd(pwd, 1024) == NULL)
		return (EXIT_FAILURE);
	printf("%s\n", pwd);
	return (EXIT_SUCCESS);
}
