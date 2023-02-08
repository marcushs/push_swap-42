/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_b_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:02:05 by hleung            #+#    #+#             */
/*   Updated: 2023/02/08 10:02:07 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_count_rarb_a(t_stack *a, t_stack *b, long nb)
{
	int	i;

	i = find_target_index_a(a, nb);
	if (i < find_index(b, nb))
		i = find_index(b, nb);
	return (i);
}

int	ft_count_rrarrb_a(t_stack *a, t_stack *b, long nb)
{
	int	i;

	i = 0;
	if (find_target_index_a(a, nb))
		i = lst_size(a) - find_target_index_a(a, nb);
	if (i < find_index_back(b, nb) && find_index(b, nb))
		i = find_index_back(b, nb);
	return (i);
}

int	ft_count_rrarb_a(t_stack *a, t_stack *b, long nb)
{
	int	i;

	i = 0;
	if (find_target_index_a(a, nb))
		i = lst_size(a) - find_target_index_a(a, nb);
	i = i + find_index(b, nb);
	return (i);
}

int	ft_count_rarrb_a(t_stack *a, t_stack *b, long nb)
{
	int	i;

	i = 0;
	if (find_index(b, nb))
		i = find_index_back(b, nb);
	i = i + find_target_index_a(a, nb);
	return (i);
}
