/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:25:30 by lde-sous          #+#    #+#             */
/*   Updated: 2023/02/16 16:54:49 by lde-sous         ###   ########.fr       */
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
	t_stack	stack_a;

	i = 1;
	while (av[i])
	{
		saddfront(&stack_a, stacknew(ft_atoi(av[i])));
		i++;
	}
	printlist(&stack_a);
	
	return (0);
}

/*int	main(int ac, char **av)
{
	if (ft_isdigit(av[1][i]
	if (check_errors(av[1]) == 1)
		write(2, "Error\n", 6);
	
	return (0);
}*/
