/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_combo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:03:34 by hleung            #+#    #+#             */
/*   Updated: 2023/02/08 10:09:08 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_run_rarb(t_stack **a, t_stack **b, long nb, char c)
{
	if (c == 'a')
	{
		while ((*a)->nb != nb && find_target_index_b(*b, nb) > 0)
			ft_rr(a, b, 'p');
		while ((*a)->nb != nb)
			ft_ra(a, 'p');
		while (find_target_index_b(*b, nb) > 0)
			ft_rb(b, 'p');
		ft_pb(a, b, 'p');
	}
	else
	{
		while ((*b)->nb != nb && find_target_index_a(*a, nb) > 0)
			ft_rr(a, b, 'p');
		while ((*b)->nb != nb)
			ft_rb(b, 'p');
		while (find_target_index_a(*a, nb) > 0)
			ft_ra(a, 'p');
		ft_pa(b, a, 'p');
	}
	return (-1);
}

int	ft_run_rrarrb(t_stack **a, t_stack **b, long nb, char c)
{
	if (c == 'a')
	{
		while ((*a)->nb != nb && find_target_index_b(*b, nb) > 0)
			ft_rrr(a, b, 'p');
		while ((*a)->nb != nb)
			ft_rra(a, 'p');
		while (find_target_index_b(*b, nb) > 0)
			ft_rrb(b, 'p');
		ft_pb(a, b, 'p');
	}
	else
	{
		while ((*b)->nb != nb && find_target_index_a(*a, nb) > 0)
			ft_rrr(a, b, 'p');
		while ((*b)->nb != nb)
			ft_rrb(b, 'p');
		while (find_target_index_a(*a, nb) > 0)
			ft_rra(a, 'p');
		ft_pa(b, a, 'p');
	}
	return (-1);
}

int	ft_run_rrarb(t_stack **a, t_stack **b, long nb, char c)
{
	if (c == 'a')
	{
		while ((*a)->nb != nb)
			ft_rra(a, 'p');
		while (find_target_index_b(*b, nb) > 0)
			ft_rb(b, 'p');
		ft_pb(a, b, 'p');
	}
	else
	{
		while ((*b)->nb != nb)
			ft_rb(b, 'p');
		while (find_target_index_a(*a, nb) > 0)
			ft_rra(a, 'p');
		ft_pa(b, a, 'p');
	}
	return (-1);
}

int	ft_run_rarrb(t_stack **a, t_stack **b, long nb, char c)
{
	if (c == 'a')
	{
		while ((*a)->nb != nb)
			ft_ra(a, 'p');
		while (find_target_index_b(*b, nb) > 0)
			ft_rrb(b, 'p');
		ft_pb(a, b, 'p');
	}
	else
	{
		while ((*b)->nb != nb)
			ft_rrb(b, 'p');
		while (find_target_index_a(*a, nb) > 0)
			ft_ra(a, 'p');
		ft_pa(b, a, 'p');
	}
	return (-1);
}
