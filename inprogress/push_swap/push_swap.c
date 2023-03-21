/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:25:30 by lde-sous          #+#    #+#             */
/*   Updated: 2023/03/20 14:01:23 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printlist(t_stack *head)
{
	t_stack	*temp;

	temp = head;
	while (temp != NULL)
	{
		ft_printf("\n%d - ", temp->content);
		temp = temp->next;
	}
	ft_printf("\n");
}

int	main(int ac, char **av)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		length;

	if (av[1] == 0)
		return (0);
	length = ac - 1;
	stack_b = NULL;
	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (0);
	i = 1;
	if (check_errors(av) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	stack_a->content = ft_atoi(av[i]);
	while (av[++i])
		saddback(stack_a, stacknew(ft_atoi(av[i])));
	ft_printf("stack A\n");
	printlist(stack_a);
	ft_printf("stack B\n");
	printlist(stack_b);
	ft_printf("\n");
	return (0);
}
