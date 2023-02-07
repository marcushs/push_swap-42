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
#include "../../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = NULL;
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
		solve(&a);
	}
	lst_clear(&a);
	return (0);
}
