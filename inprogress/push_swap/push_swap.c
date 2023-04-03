/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:25:30 by lde-sous          #+#    #+#             */
/*   Updated: 2023/04/03 18:03:51 by lde-sous         ###   ########.fr       */
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

void	sort_selector(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_csize;

	stack_csize = stsize(*stack_a);
	if (stack_csize == 2)
		sort_two(stack_a);
	else if (stack_csize == 3)
		sort_three(stack_a);
	else if (stack_csize == 4)
		sort_four(stack_a, stack_b);
	else if (stack_csize == 5)
		sort_five(stack_a, stack_b);
	else
		radix(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*temp_arr;

	(void)ac;
	if (av[1] == 0)
		return (0);
	stack_b = NULL;
	stack_a = NULL;
	i = 1;
	if (check_errors(av) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	temp_arr = index_arr(av, ac);
	stack_a = stacknew(temp_arr[0]);
	while (--ac > 1)
		saddback(stack_a, stacknew(temp_arr[i++]));
	printlist(stack_a);
	ft_printf("\n");
	ft_printf("\n");
	if (is_sorted(&stack_a, &stack_b) == 0)
		sort_selector(&stack_a, &stack_b);
	printlist(stack_a);
	ft_printf("\n");
	ft_printf("\n");
	stclear(&stack_a);
	free(temp_arr);
	return (0);
}
