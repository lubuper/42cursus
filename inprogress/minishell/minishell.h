/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:28:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/16 22:14:07 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
#include <dirent.h>


/*typedef struct  s_commands
{
    char    *pwd;
    char    *cd;
    char    *echo;
    char    *export;
    char    *unset;
    char    *env;
    char    *exit;
}   			t_commands;
*/

typedef struct  s_env
{
    char    *env_var;
    void    *next;
}       t_env;

typedef struct s_attr
{
    int     nb_tokens;
    int     index;
    char    **s_arr;
}       t_attr;

// functions
void 	command(const char *input);
void	echo(const char *input);
char    **get_tokens(char *str, t_attr t);
void    free_tokens(char **tokens, t_attr t);
void	ft_print_array(char **array, int nb);

// commands
int pwd();

// aux
char    *white_sp_rm(const char *str);
char	*trim_back(const char *input);
void    cd(const char *input);

#endif
