/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:50:21 by lde-sous          #+#    #+#             */
/*   Updated: 2023/01/12 18:14:47 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	max(int *tab, unsigned int len)
{
	unsigned int	i;
	int	store;

	i = 0;
	store = tab[i];
	while (i < len)
	{
		if (store < tab[i])
			store = tab[i];
		i++;
	}
	return (store);
}

int	main(void)
{
	int	arr[] = {4, 50, 3, 1, 90, -1, 0};
	printf("%d\n", max(arr, 7));
}
