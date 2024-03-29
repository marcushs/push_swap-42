/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_1_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:43:30 by hleung            #+#    #+#             */
/*   Updated: 2023/05/10 14:26:42 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	count_elements(char *arg)
{
	int	count;

	count = 0;
	while (*arg)
	{
		while (*arg && *arg == ' ')
			arg++;
		if (*arg)
		{
			count++;
			arg++;
		}
		while (*arg && *arg != ' ')
			arg++;
	}
	return (count);
}

static long	*strings_to_arr(char **strs, int count)
{
	int		i;
	long	num;
	long	*arr;

	if (!check_char_strs(strs))
		free_error_exit((void **)&strs, &free_2d_array);
	arr = (long *)malloc(sizeof(long) * count);
	if (!arr)
		free_error_exit((void **)&strs, &free_2d_array);
	i = -1;
	while (++i < count)
	{
		if (check_length(strs[i]) > 11)
			free_2d_error_exit((void **)&strs, (void **)&arr);
		num = ft_atoi(strs[i]);
		if (num > INT32_MAX || num < INT32_MIN)
			free_2d_error_exit((void **)&strs, (void **)&arr);
		arr[i] = num;
	}
	return (arr);
}

t_stack	*check_1arg(char *argv)
{
	char	**strings;
	long	*arr;
	int		count;
	t_stack	*a;

	count = count_elements(argv);
	if (count == 0)
		exit(0);
	strings = ft_split(argv, ' ');
	if (!strings)
		exit(0);
	arr = strings_to_arr(strings, count);
	free_2d_array((void **)&strings);
	if (!check_double(arr, count))
		free_error_exit((void **)&arr, &free_normal_arr);
	a = arr_to_lst(arr, count);
	if (!a)
		free_error_exit((void **)&arr, &free_normal_arr);
	free_normal_arr((void **)&arr);
	return (a);
}
