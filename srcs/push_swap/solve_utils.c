/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:03:53 by hleung            #+#    #+#             */
/*   Updated: 2023/02/08 10:06:44 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

long	find_max(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*last;
	long	max;

	tmp = *head;
	last = (*head)->prev;
	max = tmp->nb;
	while (1)
	{
		if (tmp->nb > max)
			max = tmp->nb;
		if (tmp == last)
			return (max);
		tmp = tmp->next;
	}
}

long	find_min(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*last;
	long	min;

	tmp = *head;
	last = (*head)->prev;
	min = tmp->nb;
	while (1)
	{
		if (tmp->nb < min)
			min = tmp->nb;
		if (tmp == last)
			return (min);
		tmp = tmp->next;
	}
}

int	find_max_index(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*last;
	long	max;
	int		index;

	tmp = *head;
	last = (*head)->prev;
	index = 0;
	max = tmp->nb;
	while (1)
	{
		if (tmp->nb > max)
		{
			max = tmp->nb;
			index = tmp->index;
		}
		if (tmp == last)
			return (index);
		tmp = tmp->next;
	}
}

int	find_min_index(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*last;
	long	min;
	int		index;

	tmp = *head;
	last = (*head)->prev;
	min = tmp->nb;
	index = 0;
	while (1)
	{
		if (tmp->nb < min)
		{
			min = tmp->nb;
			index = tmp->index;
		}
		if (tmp == last)
			return (index);
		tmp = tmp->next;
	}
}

int	is_sorted(t_stack **head)
{
	t_stack	*tmp;
	long	current;

	if (lst_size(*head) == 1)
		return (1);
	tmp = *head;
	while (1)
	{
		current = tmp->nb;
		if (current > tmp->next->nb && tmp != (*head)->prev)
			return (0);
		if (tmp == (*head)->prev)
			return (1);
		tmp = tmp->next;
	}
}
