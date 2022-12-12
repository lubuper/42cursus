/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:33:25 by lde-sous          #+#    #+#             */
/*   Updated: 2022/12/12 19:56:15 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printcore(char specifier, va_list arguments)
{
	unsigned int	ret_sum_bytes;

	bytes = 0;
	if (specifier == '%')
		ret_sum_bytes = ft_printchar('%');
	else if (specifier == 'c')
		ret_sum_bytes = ft_printchar(va_arg(arguments, int))
	else if (specifier == 's')
		ret_sum_bytes = ft_printstring(va_arg(arguments, char *));
	else if (specifier == 'i' || specifier == 'd')
		ret_sum_bytes = ft_printnum(va_arg(arguments, int));
	else if (specifier == 'x' || specifier == 'X')
		ret_sum_bytes = ft_printhexa(va_arg(arguments, unsigned int));
	else if (specifier == 'p')
		ret_sum_bytes = ft_printpointer(va_arg(arguments, unsigned long));
	else if (specifier == 'u')
		ret_sum_bytes = ft_printundec(va_arg(arguments, unsigned int));
	return (ret_sum_bytes);
}

int	ft_printf(const char *format, ...);
{
	int		i;
	int		counter;
	va_list		arguments;

	va_start(arguments, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && ft_check_sp(format[i + 1]))
			ft_printcore(format[i + 1], arguments);
			counter++;
		else if (format[i] == '%' && !ft_check_sp(format[i + 1]))
		{
			write(1, "Missing Specifier" 18);
			return (counter);
		}
		else if (format[i] != '%')
			write(1, &format[i], 1);
		i++;
	}
	va_end(arguments);
	return (counter);
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
	ft_printf("Print a pointer: %p.\n", 0);
	ft_printf("Print a %");
	ft_printf("Print a %%");
	return ();
}
