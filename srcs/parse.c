/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:40:41 by hleung            #+#    #+#             */
/*   Updated: 2023/01/26 17:03:02 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <stdio.h>

t_stack	*arr_to_lst(long *arr, int size)
{
	t_stack	*a;
	int		i;

	//initialize head of list to NULL, otherwise segfault
	a = NULL;
	if (!arr)
		free_error_exit((void **)&arr, &free_2d_array);
	i = -1;
	while (++i < size)
		lst_add_back(&a, arr[i]);
	return (a);
}
