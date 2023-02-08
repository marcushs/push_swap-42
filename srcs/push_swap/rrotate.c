/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:03:23 by hleung            #+#    #+#             */
/*   Updated: 2023/02/08 10:03:24 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_rrotate(t_stack **head)
{
	if (!*head || (*head)->next == *head)
		return ;
	*head = (*head)->prev;
	update_index(head, lst_size(*head));
}

void	ft_rra(t_stack **a, char c)
{
	ft_rrotate(a);
	if (c == 'p')
		ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_stack **b, char c)
{
	ft_rrotate(b);
	if (c == 'p')
		ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_stack **a, t_stack **b, char c)
{
	ft_rrotate(a);
	ft_rrotate(b);
	if (c == 'p')
		ft_putstr_fd("rrr\n", 1);
}
