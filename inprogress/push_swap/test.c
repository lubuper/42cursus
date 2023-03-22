/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:42:32 by lde-sous          #+#    #+#             */
/*   Updated: 2023/03/17 13:45:27 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	isbig(ssize_t num)
{
	if (num > 2147483647 || num < -2147483648)
		return (1);
	return (0);
}

int	isnum(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		if (av[i][j] == '+' || av[i][j] == '-')
			j++;
		while (av[i][j])
		{
			if (av[i][j] >= '0' && av[i][j] <= '9')
				j++;
			else
				return (0);
		}
		i++;
		j = 0;
	}
	return (1);
}

int	hasdup(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i + 1])
	{
		j = i + 1;
		while (av[j])
		{
			if (avdiff(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_errors(char **av)
{
	int	i;

	if (isnum(av) == 0 || hasdup(av) == 1)
		return (1);
	i = 1;
	while (av[i])
	{
		if (isbig(spatoi(av[i])) == 1)
			return (1);
		i++;
	}
	return (0);
}


int	ft_atoi(const char *nptr)
{
	int	sign;
	int	i;
	int	result;

	sign = 1;
	i = 0;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || fd < 0)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return ;
}

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

t_stack	*santipenu(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

long long	spatoi(const char *nptr)
{
	long long	sign;
	int			i;
	long long	result;

	sign = 1;
	i = 0;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

int	avdiff(char *av1, char *av2)
{
	int	i;

	i = 0;
	while (av1[i] && av2[i] && av1[i] == av2[i])
		i++;
	return ((unsigned char)av1[i] - (unsigned char)av2[i]);
}

void	rotate_a(t_stack **stack_a)
{
	int		temp;
	t_stack	*temporary;

	if (!*stack_a)
		return ;
	temp = (*stack_a)->content;
	temporary = *stack_a;
	while (temporary->next != NULL)
	{
		temporary->content = temporary->next->content;
		temporary = temporary->next;
	}
	temporary->content = temp;
	printf("ra\n");
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!*stack_b)
		return ;
	temp = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	*stack_b = temp;
	printf("pa\n");
}

void	push_b(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*temp;

	if (!*stack_a)
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = *stack_b;
	*stack_b = *stack_a;
	*stack_a = temp;
	printf("pb\n");
}

int	stsize(t_stack *stack)
{
	int	size;
	
	size = 1;
	if (!stack)
		return (0);
	if (stack)
	{
		while (stack->next)
		{
			stack = stack->next;
			size++;
		}
	}
	return (size);
}

int	maxbits(t_stack **stack)
{
	t_stack	*element;
	int		maxb;
	int		bigg;
	
	element = *stack;
	maxb = 0;
	bigg = element->content;
	while (element->next)
	{
		if (bigg < element->content)
			bigg = element->content;
		element = element->next;
	}
	while ((bigg >> maxb) != 0)
		maxb++;
	return (maxb);
}

int	is_sorted(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*element;

	element = *stack_a;
	while (element->next != 0)
	{
		printf("is_sorted in while loop\n");
		if (element->content > element->next->content && !(*stack_b))
			return (0);
		element = element->next;
	}
	return (1);
}

void	radix(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	j;
	int	size;
	int	mbits;
	
	i = 0;
	size = stsize(*stack_a);
	mbits = maxbits(stack_a);
	while (i < mbits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->content >> i) & 1) == 1)
				rotate_a(stack_a);
			else
				push_b(stack_b, stack_a);
			j++;
		}
		while (stsize(*stack_b) != 0)
			push_a(stack_a, stack_b);
		i++;
	}
}

void	printlist(t_stack *head)
{
	t_stack	*temp;

	temp = head;
	while (temp != NULL)
	{
		printf("\n%d - ", temp->content);
		temp = temp->next;
	}
	printf("\n");
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
	if (is_sorted(&stack_a, &stack_b) == 0)
		radix(&stack_a, &stack_b);
	printf("stack A\n");
	printlist(stack_a);
	printf("stack B\n");
	printlist(stack_b);
	printf("\n");
	return (0);
}
