/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 20:02:46 by lde-sous          #+#    #+#             */
/*   Updated: 2022/11/05 12:01:52 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(void)
{
	char	x = 'a';
	char	y = '+';
	char	z = '7';
	char	u = 130;
	char	r = 9;
	char	strc[] = "this is not a test";
	char	str[] = "this is a test string";
	char	strv[] = " ";
	char	strd[] = 

	printf("%c\n", ft_toupper(x));
	printf("%c\n", toupper(x));
	printf("%c\n", ft_toupper(y));
	printf("%c\n", toupper(y));

	printf("%c\n", ft_tolower(x));
	printf("%c\n", tolower(x));
	printf("%c\n", ft_tolower(y));
	printf("%c\n", tolower(y));

	printf("%d\n", ft_isalpha(x));
	printf("%d\n", isalpha(x));
	printf("%d\n", ft_isalpha(y));
	printf("%d\n", isalpha(y));

	printf("%d\n", ft_isalnum(z));
	printf("%d\n", isalnum(z));
	printf("%d\n", ft_isalnum(y));
	printf("%d\n", isalnum(y));

	printf("%d\n", ft_isascii(u));
	printf("%d\n", isascii(u));
	printf("%d\n", ft_isascii(x));
	printf("%d\n", isascii(x));

	printf("%d\n", ft_isdigit(x));
	printf("%d\n", isdigit(x));
	printf("%d\n", ft_isdigit(z));
	printf("%d\n", isdigit(z));
		
	printf("%d\n", ft_isprint(x));
	printf("%d\n", isprint(x));
	printf("%d\n", ft_isprint(r));
	printf("%d\n", isprint(r));
	
	printf("%d\n", ft_bzero(x));
	printf("%d\n", bzero(x));
	
	printf("%d\n", ft_strlen(str));
	printf("%d\n", strlen(str));

	printf("%d\n", ft_strlcpy(strv, str, 9));
	printf("%d\n", strlcpy(strv, str, 9));

	printf("%d\n", ft_strncmp(strv, strc, 9));
	printf("%d\n", strncmp(strv, strc, 9));

	printf("%s\n", ft_strchr(strv, '@'));
	printf("%s\n", strchr(strv, '@'));

	printf("%s\n", (char *)ft_memset(str, , 9));
	printf("%s\n", (char *)memset(str, , 9));

	return (0);
}
