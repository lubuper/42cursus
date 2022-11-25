/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:05:10 by lde-sous          #+#    #+#             */
/*   Updated: 2022/11/25 16:28:19 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <strings.h>
# include <stddef.h>
# include <ctype.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*get_next_line(int fd);
char	*readnsave(int fd, char *str);
char	*save_rest(char *str);
char	*ft_gline(char *str);

size_t	ft_strlen(char *s);
void	*ft_calloc(size_t nmemb, size_t size);
char	*str_join_mod(char *str1, char *str2);
char	*ft_strchr_mod(char *str, int c);

#endif
