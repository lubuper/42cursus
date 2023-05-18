/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/05/18 22:14:14 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
    change directory to path given in input string
    > format: "cd <path>"
    > status: working for the most part
*/

void cd(t_attr attr)
{
    char *current_path;
    char *destiny_path;

    if (attr.nb_tokens > 2)
    {
        ft_putstr_fd("minishell: cd: too many arguments\n", 1);
        return ;
    }
    destiny_path = attr.s_arr[1];
    if (!destiny_path)
        destiny_path = getenv("HOME");
    current_path = getcwd(NULL, 0);
    if (!current_path)
        return ;
    

    printf("current path: %s\n", current_path);

    if (chdir(destiny_path)) // Change directory to path given in input
        printf("minishell: cd: %s: No such file or directory\n", attr.s_arr[1]);
    else
        printf("Directory changed to: %s\n", getcwd(NULL, 0));
    free(current_path);
}
