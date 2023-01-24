/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcus <marcus@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:06:09 by hleung            #+#    #+#             */
/*   Updated: 2023/01/24 20:19:20 by marcus           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

void	check_char(char **strings)
{
	int	i;
	int	j;

	i = -1;
	while (strings[++i])
	{
		j = -1;
		while (strings[i][++j])
		{
			if (!ft_isdigit(strings[i][j]))
			{
				free_2d_array((void **)&strings);
				print_message_exit();
			}
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
