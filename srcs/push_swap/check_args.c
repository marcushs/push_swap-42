/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:43:37 by hleung            #+#    #+#             */
/*   Updated: 2023/05/10 14:35:20 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
		return (0);
	if (!check_char_strs(strs))
		return (free_2d_array((void **)&strs), 0);
	i = -1;
	while (strs[++i])
	{
		if (check_length(strs[i]) > 11)
			return (free_2d_array((void **)&strs), 0);
		num = ft_atoi(strs[i]);
		if (num > 2147483647 || num < -2147483648)
			return (free_2d_array((void **)&strs), 0);
		**arr = num;
		(*arr)++;
	}
	return (free_2d_array((void **)&strs), 1);
}

static void	args_to_arr(int argc, char **argv, long *arr)
{
	long	num;
	long	*tmp;
	int		i;
	int		count;

	tmp = arr;
	i = 0;
	while (++i < argc)
	{
		count = count_elements(argv[i]);
		if (count == 1)
		{
			if (!check_char(argv[i]) || check_length(argv[i]) > 11)
				free_error_exit((void **)&tmp, &free_normal_arr);
			num = ft_atoi(argv[i]);
			if (num > 2147483647 || num < -2147483648)
				free_error_exit((void **)&tmp, &free_normal_arr);
			*arr = num;
			arr++;
		}
		if (count > 1 && !strs_to_arr(argv[i], &arr))
			free_error_exit((void **)&tmp, &free_normal_arr);
	}
}

t_stack	*check_args(int argc, char **argv)
{
	int		count;
	long	*arr;
	t_stack	*a;

	a = NULL;
	count = count_total_elements(argv);
	if (!count)
		exit(0);
	arr = (long *)malloc(sizeof(long) * count);
	if (!arr)
	{
		ft_putstr_fd("Malloc error\n", 2);
		exit(0);
	}
	args_to_arr(argc, argv, arr);
	if (!check_double(arr, count))
		free_error_exit((void **)&arr, &free_normal_arr);
	a = arr_to_lst(arr, count);
	if (!a)
		free_error_exit((void **)&arr, &free_normal_arr);
	free_normal_arr((void **)&arr);
	return (a);
}
