/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:30:18 by lde-sous          #+#    #+#             */
/*   Updated: 2023/02/22 14:57:32 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stacknew(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	if (new)
	{
		new->content = content;
		new->next = NULL;
	}
	return (new);
}

void	saddfront(t_stack *stack, t_stack *new)
{
	if (new)
	{
		if (stack)
			new->next = stack;
		stack = new;
	}
}

t_stack	*slast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	if (stack)
	{
		while (stack->next != NULL)
			stack = stack->next;
	}
	return (stack);
}

void	saddback(t_stack *stack, t_stack *new)
{
	t_stack	*temp;

	if (!new)
		return ;
	temp = slast(stack);
	if (!stack)
	{
		stack = new;
		return ;
	}
	temp->next = new;
}

/*int	main(void)
{
	int		tester;
	t_stack	*testl;

	tester = 42;
	ft_printf("Tester = %d\n", tester);
	testl = stacknew(43);
	ft_printf("%d\n", testl->content);
	return (0);
}*/
