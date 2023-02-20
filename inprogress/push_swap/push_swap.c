/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:25:30 by lde-sous          #+#    #+#             */
/*   Updated: 2023/02/20 18:28:55 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printlist(t_stack *head)
{
	t_stack *temp = head;
	while (temp != NULL)
	{
		ft_printf("%d - ", temp->content);
		temp = temp->next;
	}
	ft_printf("\n");
}

int	main(int ac, char **av)
{
	int	i;
	char	**arr;
	t_stack	*stack_a;
	int	length;

	i = 0;
	if (ac < 2)
		return (0);
	else if (ac == 2)
	{
		length = ft_stringcounter(av[1], ' ');
		arr = ft_split(av[1], ' ');
		stack_a = malloc(sizeof(t_stack) * length);
		while (length--)
			saddback(stack_a, stacknew(ft_atoi(arr[i++])));
		printlist(stack_a);
	}
	else if (ac > 2)
	{
		length = ac - 1;
		stack_a = malloc(sizeof(t_stack) * length);
		while (length--)
		{
			saddback(stack_a, stacknew(ft_atoi(av[i++])));
			ft_printf("%d\n", stack_a);
		}
		printlist(stack_a);

	}
	
	return (0);
}
