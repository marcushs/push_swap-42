/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_1_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:43:30 by hleung            #+#    #+#             */
/*   Updated: 2023/01/26 15:38:30 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <stdio.h>

static int	count_elements(char **strings)
{
	int	i;

	i = 0;
	while (strings[i])
		i++;
	return (i);
}

static long	*strings_to_arr(char **strs, int count)
{
	int		i;
	long	num;
	long	*arr;

	arr = (long *)malloc(sizeof(long) * count);
	if (!arr)
		free_and_exit((void **)&strs, &free_2d_array);
	i = -1;
	while (++i < count)
	{
		num = ft_atoi(strs[i]);
		if (num > 2147483647 || num < -2147483648)
		{
			free_2d_array((void **)&strs);
			free_and_exit((void **)&arr, &free_normal_arr);
		}
		arr[i] = num;
	}
	return (arr);
}

void	check_1arg(char *argv)
{
	char	**strings;
	long	*arr;
	int		count;

	strings = ft_split(argv, ' ');
	if (!strings)
		print_message_exit();
	count = count_elements(strings);
	if (count < 2)
		{
			free_2d_array((void **)&strings);
			exit(0);
		}
	check_char_strs(strings);
	arr = strings_to_arr(strings, count);
	if (!check_double(arr, count))
	{
		free_2d_array((void **)&strings);
		free_and_exit((void **)&arr, &free_normal_arr);
	}
	// for (int i = 0; i < count; i++)
	// 	printf("%ld ", arr[i]);
	free_normal_arr((void **)&arr);
}
