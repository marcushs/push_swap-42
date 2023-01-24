/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcus <marcus@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:33:54 by hleung            #+#    #+#             */
/*   Updated: 2023/01/24 16:11:29 by marcus           ###   ########lyon.fr   */
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
		strings = parse_arg_to_strings(argv[1]);
		for (int i = 0; strings[i]; i++)
			printf("%s ", strings[i]);
	}
	return (0);
}
