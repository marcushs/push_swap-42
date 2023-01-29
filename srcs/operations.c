/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcus <marcus@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:12:13 by hleung            #+#    #+#             */
/*   Updated: 2023/01/29 07:59:10 by marcus           ###   ########lyon.fr   */
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

void	ft_sa(t_stack **a)
{
	int		size;

	if ((*a)->next == *a || !*a)
		return ;
	size = lst_size(*a);
	if (size == 2)
		*a = (*a)->next;
	else
		update_ptr_swap(a);
	(*a)->index = 0;
	(*a)->next->index = 1;
	ft_putstr_fd("sa\n", 1);
}
