/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:51:22 by alexfern          #+#    #+#             */
/*   Updated: 2023/05/18 22:48:15 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
    removes the spaces at the end of the string and
    returns the new string without the spaces at the
    end of the string.
*/

char	*trim_back(const char *input)
{
	char *result;
	int i;
	int j;
	
	i = 0;
	while (input[i] == ' ')
		i++;
	result = malloc(sizeof(char) * (ft_strlen(input) - i) + 1);
	if (!result)
		return (NULL);
	j = 0;
	while (input[i])
	{
		result[j] = input[i];
		j++;
		i++;
	}
	result[j] = '\0';
	return (result);
}

/*
    removes the spaces from the string and returns the
    new string without the spaces in the middle of the
    string and at the end of the string.
*/

char    *white_sp_rm(const char *str)
{
    char    *output;
    int     i;
    int     j;
	
    output = malloc(sizeof(char) * 4);
    if (!output)
        return (0);
    i = 0;
    j = 0;
    while (str[i])
    {
        if (str[i] == ' ')
            i++;
        else
        {
            output[j] = str[i];
            j++;
        }
        i++;
    }
        output[3] = 0;
    return (output);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	int	i;
	
	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] == str2[i])
			i++;
		else if (str1[i] > str2[i])
			return (1);
		else if (str2[i] > str1[i])
			return (-1);
	}
	return (0);
}

int		flag_counter(char *str, char c)
{
	int		i;
	int		result;
	
	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] == c)
			result++;
		i++;
	}
	return (result);
}

char	*dequoter(char *str)
{
	int		i;
	int		flagdouble;
	int		flagsimple;
	char	*arranged;

	arranged = malloc(sizeof(char) * ft_strlen(str) + 1);// malloc esta mal feito - pensar noutra forma de determinar o tamanho, dependendo se as quotes sao double ou nao	
	flagdouble = flag_counter(str, 34); //nao ha double quotes (em ascii 34), se == IMPAR ha quotes abertas; se == PAR, quotes fechadas, se flagsimple > 0 ENTAO  == 0;.
	flagsimple = flag_counter(str, 39); // nao ha simple quotes (em ascii 39)
	if (flagdouble % 2 == 1 || flagsimple % 2 == 1)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (flagdouble > 0 && str[i] == 34)
			{
				flagsimple = 0;
				i++;
			}
		if (flagsimple > 0 && str[i] == 39)
		{
			flagdouble = 0;
			i++;
		}
		arranged[i] = str[i];
		i++;
	}
	printf(arranged);
	return (arranged); //nao esquecer de dar free!!!
}