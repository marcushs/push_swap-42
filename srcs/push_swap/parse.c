/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcus <marcus@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:40:41 by hleung            #+#    #+#             */
/*   Updated: 2023/01/27 21:07:51 by marcus           ###   ########lyon.fr   */
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
