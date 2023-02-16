/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:38:02 by lde-sous          #+#    #+#             */
/*   Updated: 2023/02/16 16:40:39 by lde-sous         ###   ########.fr       */
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
void	push_a(t_stack *stack_a, t_stack *stack_b);
void	push_b(t_stack *stack_b, t_stack *stack_a);

#endif
