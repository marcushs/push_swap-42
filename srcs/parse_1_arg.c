#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <stdio.h>

static void	check_char(char **strings)
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

char	**parse_1arg_to_strings(char *argv)
{
	char	**strings;
	long	*arr;
	int		count;

	strings = ft_split(argv, ' ');
	if (!strings)
		print_message_exit();
	count = count_elements(strings);
	if (count < 2)
		free_and_exit((void **)&strings, &free_2d_array);
	check_char(strings);
	arr = strings_to_arr(strings, count);
	if (!check_double(arr, count))
	{
		free_2d_array((void **)&strings);
		free_and_exit((void **)&arr, &free_normal_arr);
	}
	free_normal_arr((void **)&arr);
	return (strings);
}


