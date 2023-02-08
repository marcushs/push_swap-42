/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:03:09 by hleung            #+#    #+#             */
/*   Updated: 2023/02/08 10:03:10 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	update_ptr_push(t_stack **first_from, t_stack **to)
{
	t_stack	*first;
	t_stack	*second;

	first = *first_from;
	if (!*to)
	{
		first->next = first;
		first->prev = first;
	}
	else
	{
		second = *to;
		second->prev->next = first;
		first->prev = second->prev;
		second->prev = first;
		first->next = second;
	}
	*to = first;
}

static void	ft_push(t_stack **from, t_stack **to)
{
	t_stack	*first_from;
	t_stack	*second_from;

	if (!*from)
		return ;
	if ((*from)->next == *from)
	{
		update_ptr_push(from, to);
		*from = NULL;
		update_index(to, lst_size(*to));
	}
	else
	{
		first_from = *from;
		second_from = (*from)->next;
		first_from->prev->next = second_from;
		second_from->prev = first_from->prev;
		*from = second_from;
		update_ptr_push(&first_from, to);
		update_index(from, lst_size(*from));
		update_index(to, lst_size(*to));
	}
}

void	ft_pa(t_stack **b, t_stack **a, char c)
{
	ft_push(b, a);
	if (c == 'p')
		ft_putstr_fd("pa\n", 1);
}

void	ft_pb(t_stack **a, t_stack **b, char c)
{
	ft_push(a, b);
	if (c == 'p')
		ft_putstr_fd("pb\n", 1);
}
