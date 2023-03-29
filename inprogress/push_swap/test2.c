/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:12:03 by lde-sous          #+#    #+#             */
/*   Updated: 2023/03/28 16:34:53 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*sort_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	if (size != 0)
	{
		while (i < size)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i + 1];
				tab[i + 1] = tab[i];
				tab[i] = temp;
				i = 0;
			}
			i++;
		}
	}
	return (tab);
}

int	*index_arr(char **str, int ac)
{
	int	*array;
	int	*arr;
	int	*final;
	int	n;
	int	i;
	int	j;

	printf("check1");
	arr = malloc(sizeof(ac - 1));
	array = malloc(sizeof(ac - 1));
	final = malloc(sizeof(ac - 1));
	if (!arr || !array || !final)
		return (NULL);
	printf("check2");
	n = ac;
	i = 0;
	j = 0;
	while (n > 0)
	{
		array[i] = atoi(str[i + 1]);
		n--;
		i++;
	}
	printf("check3");
	arr = sort_int_tab(array, (ac - 1));
	free(array);
	i = 0;
	n = ac;
	while (ac < 0)
	{
		j = 0;
		while (j < n)
		{
			if (array[i] == arr[j])
				final[i] = j;
			j++;
		}
		ac--;
		i++;
	}
	printf("check4");
	free(arr);
	return (final);
}


int	main(int ac, char **av)
{
	int	*intarray;
	int	i;

	intarray = malloc(sizeof(ac - 1));
	if (!intarray)
		return (0);
	i = 0;
	intarray = index_arr(av, (ac - 1));
	while (i < ac)
	{
		printf("%d\n", intarray[i]);
		i++;
	}
	return (0);
}
