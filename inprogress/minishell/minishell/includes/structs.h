/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:28:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/31 20:51:53 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "macros.h"

typedef struct s_dirdoc
{
	int single_right;	// count: >
	int double_right;	// count: >>
	int	single_left;	// count: <
	int	double_left;	// count: <<
}		t_dirdoc;

typedef struct s_attr
{
	int nb_tokens;         // number of tokens
	int nb_pipes;          // number of pipes
	int index;             // index of the token
	int len_d_env;         // length of d_env
	int len_g_env;         // length of my_env
	char **tok_arr;        // array of tokens
	char **g_env;          // global environment
	char *last_path;       // last path
	char **d_env;          // duplicate environment
	char **exp_env;        //27 maio
	int len_exp_env;       //27 maio
	char **d_exp_env;      //27 maio
	int len_d_exp_env;     //27 maio
	int	n;
	t_dirdoc dirdoc;	   //struct para count redirection / heredocs
}			t_attr;

typedef struct s_exec
{
	int		i;
	int		nb_of_paths;
	char	*command;
	char	*path_srt;
	char	**all_paths;
	char	**path_command;
	char	curr_path[PATH_MAX];
	int		ret;
	pid_t	pid;
}			t_exec;

#endif