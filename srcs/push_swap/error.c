/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:06:09 by hleung            #+#    #+#             */
/*   Updated: 2023/05/10 14:28:52 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_char(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if ((i != 0 && str[i] == '-') || \
		(str[i] == '-' && (str[i + 1] < '0' || str[i + 1] > '9')) || \
		(str[i] == '+' && (str[i + 1] < '0' || str[i + 1] > '9')) || \
		(i != 0 && str[i] == '+') || !ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

int	check_char_strs(char **s)
{
	int	i;
	int	j;

	i = -1;
	while (s[++i])
	{
		j = -1;
		while (s[i][++j])
		{
			if ((j != 0 && s[i][j] == '-') || \
			(s[i][j] == '-' && (s[i][j + 1] < '0' || s[i][j + 1] > '9')) \
			|| (s[i][j] == '+' && (s[i][j + 1] < '0' || s[i][j + 1] > '9')) \
			|| (j != 0 && s[i][j] == '+') || !ft_isdigit(s[i][j]))
				return (0);
		}
	}
	return (1);
}

int	check_double(long *arr, int count)
{
	int	i;
	int	j;

	i = 0;
	if (count == 1)
		return (1);
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_length(char *s)
{
	int	len;

	len = 0;
	while (*s && (*s == ' ' || (*s >= 9 && *s <= 13)))
		s++;
	while (*s && !(*s == ' ' || (*s >= 9 && *s <= 13)))
	{
		s++;
		len++;
	}
	return (len);
}
