/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcus <marcus@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:33:54 by hleung            #+#    #+#             */
/*   Updated: 2023/02/01 12:58:57 by marcus           ###   ########lyon.fr   */
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
		solve(&a);
	}
	if (argc > 2)
	{
		a = check_args(argc, argv);
		// //printf("%d\n", find_min_index(&a));
		
		// printf("Stack a:\n");
		// lst_print(a);
		// (!is_sorted(&a) ? printf("NOT SORTED!\n") : printf("SORTED!\n"));
		solve(&a);
		// printf("Stack a:\n");
		// lst_print(a);
		// (!is_sorted(&a) ? printf("NOT SORTED!\n") : printf("SORTED!\n"));
		// printf("Stack b:\n");
		// lst_print(b);
	}
	lst_clear(&a);
	return (0);
}
