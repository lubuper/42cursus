/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:38:47 by lde-sous          #+#    #+#             */
/*   Updated: 2022/12/20 17:04:55 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printcore(char spec, va_list arguments);
int		ft_printf(const char *format, ...);
char	ft_chck(char to_check);
int		ft_printchar(char c);
int		ft_printstring(char *str);
int		ft_printhexa(unsigned int to_hex, char s);
int		ft_printnum(long num);
int		ft_printpointer(unsigned long point);
int		ft_printundec(unsigned int decimal);

#endif
