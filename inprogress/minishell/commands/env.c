/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/05/18 19:31:1:01 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_myenv	*lst_new(void *data)
{
	t_myenv	*new;

	new = malloc(sizeof(t_myenv));
	if (!new)
		return (NULL);
	if (new)
	{
		new->data = data;
		new->next = NULL;
	}
	return (new);
}

void	add_end(t_myenv **lst, t_myenv *new)
{
	t_myenv	*temp;

	if (!new)
		return ;
	temp = add_last(*lst);
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp->next = new;
}

t_myenv	*add_last(t_myenv *lst)
{
	if (!lst)
		return (NULL);
	if (lst)
	{
		while (lst->next != NULL)
		lst = lst->next;
	}
	return (lst);
}

t_myenv	*create_list(char **envp)
{
	t_myenv	*result;
	t_myenv *addenv;
	int i = 0;

	result = malloc(sizeof(t_myenv *));
	if (!result)
		return NULL;
	while (envp[i])
	{
		addenv = lst_new(envp[i]);
		add_end(&result, addenv);
		i++;
	}
	return (result);
}


void	env(char **envp)
{
	int i = 0;

	while(envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
}