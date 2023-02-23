/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:38:02 by lde-sous          #+#    #+#             */
/*   Updated: 2023/02/23 12:24:10 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}					t_stack;

void	saddfront(t_stack *stack, t_stack *new);
t_stack	*stacknew(int content);
t_stack	*slast(t_stack *stack);
void	saddback(t_stack *stack, t_stack *new);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_b, t_stack **stack_a);
int		isbig(ssize_t num);
int		check_errors(int ac, char *av);
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_swap(t_stack **stack_a, t_stack **stack_b);
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	rotate_rotate(t_stack **stack_a, t_stack **stack_b);
void	rrotate_a(t_stack **stack_a);
void	rrotate_b(t_stack **stack_b);
void	rr_ab(t_stack **stack_a, t_stack **stack_b);

#endif
