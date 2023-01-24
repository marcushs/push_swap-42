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

long	*strings_to_arr(char **strs, int count)
{
	int		i;
	long	num;
	long	*arr;

	arr = (long *)malloc(sizeof(long) * count);
	if (!arr)
	{
		free_2d_array((void **)&strs);
		print_message_exit();
	}
	i = -1;
	while (++i < count)
	{
		num = ft_atoi(strs[i]);
		if (num > 2147483647 || num < -2147483648)
		{
			free_2d_array((void **)&strs);
			free(arr);
			arr = NULL;
			print_message_exit();
		}
		arr[i] = num;
	}
	return (arr);
}

char	**parse_arg_to_strings(char *argv)
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
		print_message_exit();
	}
	check_char(strings);
	arr = strings_to_arr(strings, count);
	if (!check_double(arr, count))
	{
		free_2d_array((void **)&strings);
		free(arr);
		arr = NULL;
		print_message_exit();
	}
	free(arr);
	arr = NULL;
	return (strings);
}


