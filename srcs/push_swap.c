/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcus <marcus@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:33:54 by hleung            #+#    #+#             */
/*   Updated: 2023/01/27 12:21:24 by marcus           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*a;

	if (argc < 2)
		exit(0);
	if (argc == 2)
	{
		a = check_1arg(argv[1]);
		lst_print(a);
		printf("OK!\n");
	}
	if (argc > 2)
	{
		a = check_args(argc, argv);
		lst_print(a);
		printf("OK!\n");
	}
	lst_clear(&a);
	return (0);
}
