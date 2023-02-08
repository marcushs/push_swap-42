/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:02:55 by hleung            #+#    #+#             */
/*   Updated: 2023/02/08 10:02:57 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	update_index(t_stack **head, int size)
{
	t_stack	*tmp;

	tmp = (*head)->prev;
	while (--size >= 0)
	{
		tmp->index = size;
		tmp = tmp->prev;
	}
}
