/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:15:17 by lde-sous          #+#    #+#             */
/*   Updated: 2022/11/07 17:46:33 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tempvector;
	size_t	i;

	tempvector = malloc(sizeof(nmemb) * (size + 1));
	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (tempvector == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		tempvector[i] = 0;
		i++;
	}
	return (tempvector);
}
