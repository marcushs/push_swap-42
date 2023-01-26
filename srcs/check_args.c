/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:43:37 by hleung            #+#    #+#             */
/*   Updated: 2023/01/26 15:38:26 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <stdio.h>

static int	count_elements(char *arg)
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

static int	count_total_elements(char **argv)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	count = 0;
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] && argv[i][j] == ' ')
				j++;
			if (argv[i][j])
			{
				count++;
				j++;
			}
			while (argv[i][j] && argv[i][j] != ' ')
				j++;
		}
	}
	return (count);
}

static int	strs_to_arr(char *arg, long **arr)
{
	char	**strs;
	int		i;
	long	num;

	strs = ft_split(arg, ' ');
	if (!strs)
		print_message_exit();
	check_char_strs(strs);
	i = -1;
	while (strs[++i])
	{
		num = ft_atoi(strs[i]);
		if (num > 2147483647 || num < -2147483648)
			free_and_exit((void **)&strs, &free_2d_array);
		**arr = num;
		(*arr)++;
	}
	free_2d_array((void **)&strs);
	return (i);
}

static void	args_to_arr(int argc, char **argv, long *arr)
{
	long	num;
	int		i;
	int		count;

	i = 0;
	while (++i < argc)
	{
		count = count_elements(argv[i]);
		if (count == 1)
		{
			check_char(argv[i]);
			num = ft_atoi(argv[i]);
			if (num > 2147483647 || num < -2147483648)
				print_message_exit();
			*arr = num;
			arr++;
		}
		if (count > 1)
			strs_to_arr(argv[i], &arr);
	}
}

void	check_args(int argc, char **argv)
{
	int		count;
	long	*arr;

	count = count_total_elements(argv);
	if (!count)
		print_message_exit();
	if (count == 1)
		exit(0);
	arr = (long *)malloc(sizeof(long) * count);
	if (!arr)
		print_message_exit();
	args_to_arr(argc, argv, arr);
	if (!check_double(arr, count))
		free_and_exit((void **)&arr, &free_normal_arr);
	// for (int i = 0; i < count; i++)
	// 	printf("%ld ", arr[i]);
	free_normal_arr((void **)&arr);
}
