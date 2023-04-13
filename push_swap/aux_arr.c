/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:12:03 by lde-sous          #+#    #+#             */
/*   Updated: 2023/03/30 11:57:59 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	while (size > 0)
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i + 1];
				tab[i + 1] = tab[i];
				tab[i] = temp;
			}
			i++;
		}
		size--;
	}
}

void	filler(char **str, int *arr, int *array, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		array[i] = ft_atoi(str[i + 1]);
		arr[i] = array[i];
		i++;
	}
}

void	finalizer(int *arr, int *array, int *final, int ac)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = ac - 1;
	while (--ac > 0)
	{
		j = 0;
		while (j < n)
		{
			if (array[i] == arr[j])
			{
				final[i] = j + 1;
				break ;
			}
			j++;
		}
		i++;
	}
}

int	*index_arr(char **str, int ac)
{
	int	*array;
	int	*arr;
	int	*final;

	arr = malloc((ac - 1) * sizeof(int));
	array = malloc((ac - 1) * sizeof(int));
	final = malloc((ac - 1) * sizeof(int));
	if (!arr || !array || !final)
		return (NULL);
	filler(str, arr, array, (ac - 1));
	sort_int_tab(arr, (ac - 1));
	finalizer(arr, array, final, ac);
	free(arr);
	free(array);
	return (final);
}
