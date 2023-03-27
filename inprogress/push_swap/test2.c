/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:12:03 by lde-sous          #+#    #+#             */
/*   Updated: 2023/03/27 20:42:13 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*index_arr(char **str, int ac)
{
	int	*array;
	int	*arr;
	int	*final;
	int	n;
	int	i;
	int	j;

	arr = malloc(sizeof(ac - 1));
	array = arr;
	final = arr;
	if (!arr || !array)
		return (0);
	n = ac;
	i = 0;
	j = 0;
	while (n > 0)
	{
		array[i] = ft_atoi(str[i + 1]);
		n--;
		i++;
	}
	arr = sort_int_tab(array);
	i = 0;
	n = ac;
	while (ac < 0)
	{
		j = 0;
		while (j < n);
		{
			if (array[i] == arr[j])
				final[i] = j;
		ac--;
		i++;
	}
	
	free(array);
	free(arr);
	return (final);
}


/*while (arr[i])
{
:	if (find min
}
*/
int	main(int ac, char **av)
{
	(void)ac;
	index_arr(av, ac);
	return (0);
}
