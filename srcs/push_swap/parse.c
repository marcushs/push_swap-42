/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:40:41 by hleung            #+#    #+#             */
/*   Updated: 2023/02/08 10:03:01 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*arr_to_lst(long *arr, int size)
{
	t_stack	*a;
	int		i;

	a = NULL;
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < size)
		lst_add_back(&a, arr[i], i);
	return (a);
}
