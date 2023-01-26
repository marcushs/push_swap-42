#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <stdio.h>

int	count_element(char *arg)
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

void	parse_args(int argc, char **argv)
{
	int	i;
	int	num;
	
	i = 0;
	while(++i < argc)
	{
		if (count_element(argv[i]) == 1)
		{
			num = ft_atoi(argv[i]);
			if (num > 2147483647 || num < -2147483648)
				print_message_exit();
		}
		if (count_element(argv[i]) > 1)
		{
			
		}
	}
}
