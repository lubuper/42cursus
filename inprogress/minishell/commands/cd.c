/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/05/16 22:35:13 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
    change directory to path given in input string
    > format: "cd <path>"
    > status: not working
*/

void cd(const char *input)
{
    char *current_path;

    current_path = getcwd(NULL, 0);
    if (!current_path)
        return;

    printf("%s\n", current_path);

    if (strncmp(input, "cd ", 3) == 0)
    {
        const char *path = input + 3; // Skip "cd " prefix in input string (3 chars)
        if (chdir(ft_strjoin(current_path, path)) != 0) // Change directory to path given in input
        {
            printf("Failed to change directory.\n");
        }
        else
        {
            printf("Directory changed to: %s\n", path);
        }
    }

    free(current_path);
}
