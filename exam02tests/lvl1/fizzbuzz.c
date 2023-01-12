/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:33:31 by lde-sous          #+#    #+#             */
/*   Updated: 2023/01/09 18:52:01 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ptn(int n)
{
	char	*base;

	base = "0123456789";
	if (n > 9)
		ptn(n / 10);
	write (1, &base[n % 10], 1);
}

int	main(void)
{
	int	number;

	number = 1;
	while (number <= 100)
	{
		if (number % 3 == 0 && number % 5 == 0)
			write (1, "fizzbuzz", 8);
		else if (number % 5 == 0)
			write (1, "buzz", 4);
		else if (number % 3 == 0)
			write (1, "fizz", 4);
		else
			ptn(number);
		write (1, "\n", 1);
		number++;
	}
	return (0);
}
