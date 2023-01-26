/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:06:09 by hleung            #+#    #+#             */
/*   Updated: 2023/01/26 14:43:59 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

void	check_char(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if ((i != 0 && str[i] == '-') || \
		(i != 0 && str[i] == '+') || !ft_isdigit(str[i]))
			print_message_exit();
	}
}

void	check_char_strs(char **strings)
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
				free_and_exit((void **)&strings, &free_2d_array);
		}
	}
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
