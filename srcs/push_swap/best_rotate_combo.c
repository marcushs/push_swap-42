/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_rotate_combo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:01:48 by hleung            #+#    #+#             */
/*   Updated: 2023/02/08 10:01:50 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	best_rotate_comb_a_to_b(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = a;
	i = ft_count_rrarrb(a, b, a->nb);
	while (1)
	{
		if (i > ft_count_rarb(a, b, tmp->nb))
			i = ft_count_rarb(a, b, tmp->nb);
		if (i > ft_count_rrarrb(a, b, tmp->nb))
			i = ft_count_rrarrb(a, b, tmp->nb);
		if (i > ft_count_rarrb(a, b, tmp->nb))
			i = ft_count_rarrb(a, b, tmp->nb);
		if (i > ft_count_rrarb(a, b, tmp->nb))
			i = ft_count_rrarb(a, b, tmp->nb);
		if (tmp == a->prev)
			return (i);
		tmp = tmp->next;
	}
}

int	best_rotate_comb_b_to_a(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = b;
	i = ft_count_rrarrb_a(a, b, b->nb);
	while (1)
	{
		if (i > ft_count_rarb_a(a, b, tmp->nb))
			i = ft_count_rarb_a(a, b, tmp->nb);
		if (i > ft_count_rrarrb_a(a, b, tmp->nb))
			i = ft_count_rrarrb_a(a, b, tmp->nb);
		if (i > ft_count_rarrb_a(a, b, tmp->nb))
			i = ft_count_rarrb_a(a, b, tmp->nb);
		if (i > ft_count_rrarb_a(a, b, tmp->nb))
			i = ft_count_rrarb_a(a, b, tmp->nb);
		if (tmp == b->prev)
			return (i);
		tmp = tmp->next;
	}
}
