/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:12:59 by lde-sous          #+#    #+#             */
/*   Updated: 2023/03/27 20:08:16 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	index_arr(char **str, int ac)
{
	int	i;
	int	j;
	int	*arr;
	int	temp;
	int	t;
	int	pos;
//	int	temp_next;

	if (!str)
		return (0);
	arr = malloc(sizeof(ac - 1));
	i = 1;
	t = 0;
	temp = atoi(str[i]);
	while (ac > 1)
	{
		while (str[i])
		{
			j = i;
			while (str[j])
			{
				if (atoi(str[j]) < temp)
				{
					pos = j;
					arr[t] = j;
					temp = atoi(str[j]);
				}
				j++;
			}
			i++;
		}
		printf("order:%d\n", t);
		t++;
		ac--;
	}
	printf("pos = %d\n", pos);
	while (t > 0)
	{
		printf("%d\n", arr[t]);
		t--;
	}
	free(arr);
	return (0);
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
