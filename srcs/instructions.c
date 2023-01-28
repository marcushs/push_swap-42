/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcus <marcus@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:12:13 by hleung            #+#    #+#             */
/*   Updated: 2023/01/28 07:59:04 by marcus           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <stdio.h>

void	ft_sa(t_stack **a)
{
	t_stack	*tmp;
	//t_stack	*last;
	int		size;

	tmp = *a;
	//last = (*a)->prev;
	if (tmp->next == *a || !*a)
		return ;
	size = lst_size(*a);
	if (size == 2)
		*a = (*a)->next;
	// else
	// {
	// 	last->next = tmp->next;
	// 	tmp->next->prev = last;
	// 	tmp->next->next = tmp;
	// 	tmp->prev = tmp->next;
		

	// }
	ft_putstr_fd("sa\n", 1);
}
