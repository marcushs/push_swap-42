/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcus <marcus@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:12:13 by hleung            #+#    #+#             */
/*   Updated: 2023/01/29 07:40:12 by marcus           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <stdio.h>

void	ft_sa(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;
	int		size;

	first = *a;
	second = (*a)->next;
	if (first->next == *a || !*a)
		return ;
	size = lst_size(*a);
	if (size == 2)
		*a = (*a)->next;
	else
	{
		//next of last is now 2nd
		first->prev->next = second;
		//prev of 2nd is now last
		second->prev = first->prev;
		//prev of 3rd is now first
		second->next->prev = first;
		//next of first is now 3rd
		first->next = second->next;
		//prev of first is now 2nd
		first->prev = second;
		//next of second is now first
		second->next = first;
		*a = second;
	}
	(*a)->index = 0;
	(*a)->next->index = 1;
	ft_putstr_fd("sa\n", 1);
}
