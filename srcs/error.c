/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcus <marcus@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:06:09 by hleung            #+#    #+#             */
/*   Updated: 2023/01/27 12:37:58 by marcus           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

int	check_char(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if ((i != 0 && str[i] == '-') || \
		(i != 0 && str[i] == '+') || !ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

int	check_char_strs(char **strings)
{
	int	i;
	int	j;

	i = -1;
	while (strings[++i])
	{
		j = -1;
		while (strings[i][++j])
		{
			if ((j != 0 && strings[i][j] == '-') || \
			(j != 0 && strings[i][j] == '+') || !ft_isdigit(strings[i][j]))
				return (free_2d_array((void **)&strings), 0);
		}
	}
	return (1);
}

int	check_double(long *arr, int count)
{
	int	i;
	int	j;

	i = 0;
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
