/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:06:09 by hleung            #+#    #+#             */
/*   Updated: 2023/01/23 14:15:38 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

void	print_message_exit(void)
{
	ft_putstr_fd(ARG_ERROR, 2);
	exit(0);
}

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
				print_message_exit();
		}
	}
}