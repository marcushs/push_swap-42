/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:33:54 by hleung            #+#    #+#             */
/*   Updated: 2023/01/23 14:59:14 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	char	**strings;
	
	if (argc < 2)
		print_message_exit();
	if (argc == 2)
	{
		strings = ft_split(argv[1],' ');
		check_char(strings);
		for (int i = 0; strings[i]; i++)
			printf("%s ", strings[i]);
	}
	return (0);
}