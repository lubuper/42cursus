/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/31 20:56:12 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
    The command function handles basic command recognition
    and execution based on the input string, providing
    feedback or return values accordingly.
*/

void	command(t_attr *att)
{
	char	**tok;

	if (!att->tok_arr[att->n])
		return ;
	if (valid_dirdoc(att))
	{
		heredocs(att);
		return ;
	}
	tok = att->tok_arr;
	if (!ft_strcmp(att->tok_arr[att->n], "echo"))
		echo(*att);
	else if (ft_strcmp(tok[att->n], "pwd") == 0)
		pwd();
	else if (ft_strcmp(tok[att->n], "cd") == 0)
		cd(att);
	else if (ft_strcmp(tok[att->n], "export") == 0)
		export(att);
	else if (ft_strcmp(tok[att->n], "unset") == 0)
		unset(att);
	else if (ft_strcmp(tok[att->n], "env") == 0)
		env(att);
	else if ((ft_strcmp(tok[att->n], "exit") == 0) || (ft_strcmp(tok[0],
				"\"exit\"") == 0))
		return (ft_exit(att));
	else
		execute(att);
	return ;
}
