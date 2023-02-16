/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:25:30 by lde-sous          #+#    #+#             */
/*   Updated: 2023/02/16 15:10:16 by lde-sous         ###   ########.fr       */
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
	(void)ac;
	int	i;
	t_stack	*stack_a;

	stack_a = 0;
	i = 1;
	while (av[i])
	{
		saddfront(&stack_a, stacknew(ft_atoi(av[i])));
		i++;
	}
	return (0);
}

/*int	main(int ac, char **av)
{
	if (ft_isdigit(av[1][i]
	if (check_errors(av[1]) == 1)
		write(2, "Error\n", 6);
	
	return (0);
}*/
