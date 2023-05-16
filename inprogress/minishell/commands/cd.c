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

void    cd(const char *input)
{
    char *current_path;

    current_path = malloc(sizeof(char) * (strlen(input) + 1));
    if (!current_path)
        return ;
    current_path = getcwd(current_path, 1024);
    printf("%s\n", current_path);
    if (strncmp(input, "cd ", 3) == 0)
    {
        const char *path = input + 3;// Skip "cd " prefix in input string (3 chars) 
        chdir(ft_strjoin(current_path, path));// Change directory to path given in input
        
        /*  if (result)// Success?!
        {
            printf("Directory changed to: %s\n", path);
        }
        else
        {
            printf("chdir() erro");
        } */
        printf("Directory changed to: %s\n", current_path);
    }
}