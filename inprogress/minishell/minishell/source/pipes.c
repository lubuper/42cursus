/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:38:30 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/31 20:49:33 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* 	A IDEIA
	- pegar no que nos chega como string
		- iterar a string a procura de '|'s - ✅
			- atribuir a uma variavel o numero de '|'s existentes ✅
	- verificar o resto dos tokens com o lexer ❌
		- criar pids e forks com o numero de '|'s ❌
		- verificar se sao comandos validos ❌
			- verificar se os '|'s e os comandos validos estao em numero correcto ❌
	- atribuir cada token ao respectivo fork / child process ❌
	- executar os tokens/comandos ❌
	- fechar os fd[] ❓
	ESTA TUDO MAL
 */

int	pipework(t_attr *att)
{
	int		pid1; // create pid1
	int		pid2;
	int		fds[2]; // create file descriptors main pipe
	
	if (att->nb_pipes < 1)
		return (1);
	while (att->n <= att->nb_pipes)
	{
		if (ft_strcmp(att->tok_arr[att->n], "|") == 0 && att->tok_arr[att->n + 1])
			att->n++;
		if (ft_strcmp(att->tok_arr[att->n], "|") != 0 && att->tok_arr[att->n + 1])
		{	
			if (pipe(fds) == -1)
				return (1);
			pid1 = fork();
			if (pid1 == -1)
				return (1);
			if (pid1 == 0)
			{
				dup2(fds[1], STDIN_FILENO);
				close(fds[0]);
				close(fds[1]);
				att->n--;
 				command(att);
				att->n++;
			}
			if (ft_strcmp(att->tok_arr[att->n], "|") == 0)
				att->n++;
			pid2 = fork();
			if (pid2 == -1)
				return (1);
			if (pid2 == 0)
			{
				dup2(fds[0], STDOUT_FILENO);
  				close(fds[0]);
  				close(fds[1]);
				att->n--;
  				command(att);
				att->n++;
			}
			else
			{
				close(fds[0]);
    			close(fds[1]);
				waitpid(pid1, NULL, 0);
				waitpid(pid2, NULL, 0);
			}
		}
		att->n++;
	}
	return (0);
}