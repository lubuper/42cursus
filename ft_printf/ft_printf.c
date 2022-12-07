/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:33:25 by lde-sous          #+#    #+#             */
/*   Updated: 2022/12/07 15:48:50 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *, ...);
{

}

int	main(void)
{
	void	*p_to_main = (void *) main;
	ft_printf("Print a char: %c.\n", 'F');
	ft_printf("Print a string: %s.\n", "Hitman: Codename 47");
	ft_printf("Print a positive i: %d.\n", 47);
	ft_printf("Print a zero i: %d.\n", 0);
	ft_printf("Print a negative i: %d.\n", -42);
	ft_printf("Print a lower hex i: %x.\n", 47);
	ft_printf("Print a UPPER hex: %X.\n", 47);
	ft_printf("Print a zero hex: %x.\n", 47);
	ft_printf("Print a pointer: %p.\n, 0);
	return ();
}
