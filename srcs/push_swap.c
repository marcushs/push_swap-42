/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcus <marcus@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:33:54 by hleung            #+#    #+#             */
/*   Updated: 2023/01/30 21:34:09 by marcus           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	//t_stack	*b = NULL;

	if (argc < 2)
		exit(0);
	if (argc == 2)
	{
		a = check_1arg(argv[1]);
		printf("Stack a:\n");
		lst_print(a);
		// printf("Stack b:\n");
		// lst_print(b);
		// ft_pb(&a, &b);
		// ft_pb(&a, &b);
		solve_3(&a);
		printf("Stack a:\n");
		lst_print(a);
		// printf("Stack b:\n");
		// lst_print(b);
	}
	if (argc > 2)
	{
		a = check_args(argc, argv);
		printf("Stack a:\n");
		lst_print(a);
		(!is_sorted(&a) ? printf("NOT SORTED!\n") : printf("SORTED!\n"));
		solve_5_or_under(&a);
		printf("Stack a:\n");
		lst_print(a);
		(!is_sorted(&a) ? printf("NOT SORTED!\n") : printf("SORTED!\n"));
		// printf("Stack b:\n");
		// lst_print(b);
	}
	lst_clear(&a);
	return (0);
}
