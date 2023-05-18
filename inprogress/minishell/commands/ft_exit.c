/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/05/18 17:01:46 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void ft_exit(const char *input, t_attr attr)
{
	printf("exit\n");

    int return_value = 0;
    int i = 0;
    
    (void)input;
    
    if (attr.nb_tokens == 1)
    {
        return_value = 0;
    }
    else if (attr.nb_tokens == 2)
    {
        const char *arg = attr.s_arr[1];
        int is_numeric = 1;
        
        while (arg[i])
        {
            if (!isdigit(arg[i++]))
            {
                is_numeric = 0;
                break;
            }
        }
        
        if (is_numeric)
        {           return_value = ft_atoi(arg);
        }
        else
        {
            printf("minishell: exit: %s: numeric argument required\n", arg);
            return_value = 2;
        }
    }
    else
    {
        printf("minishell: exit: too many arguments\n");
        return;
    }

    // printf("Exiting minishell with code %d\n", return_value);
    exit(return_value);
}
