/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcus <marcus@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:12:13 by hleung            #+#    #+#             */
/*   Updated: 2023/01/29 19:12:03 by marcus           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <stdio.h>

void	update_ptr_swap(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;
	
	if (!*head || (*head)->next == *head)
		return ;
	first = *head;
	second = (*head)->next;
	first->prev->next = second;
	second->prev = first->prev;
	second->next->prev = first;
	first->next = second->next;
	second->next = first;
	first->prev = second;
	*head = second;
}

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

void	ft_sa(t_stack **head)
{
	int		size;

	if ((*head)->next == *head || !*head)
		return ;
	size = lst_size(*head);
	if (size == 2)
		*head = (*head)->next;
	else
		update_ptr_swap(head);
	update_index(head, size);
	ft_putstr_fd("sa\n", 1);
}

void	ft_ra(t_stack **head)
{
	if (!*head || (*head)->next == *head)
		return ;
	*head = (*head)->next;
	update_index(head, lst_size(*head));
	ft_putstr_fd("ra\n", 1);
}

void	ft_rra(t_stack **head)
{
	if (!*head || (*head)->next == *head)
		return ;
	*head = (*head)->prev;
	update_index(head, lst_size(*head));
	ft_putstr_fd("rra\n", 1);
}

void	ft_pb(t_stack **a, t_stack **b)
{
	if (!*a)
		return ;
	
}
