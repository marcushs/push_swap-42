/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DCLL.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:46:54 by hleung            #+#    #+#             */
/*   Updated: 2023/05/05 15:21:48 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*lst_new(long nb, int index)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->index = index;
	new->next = new;
	new->prev = new;
	return (new);
}

void	lst_add_back(t_stack **head, long **arr, int index)
{
	t_stack	*new;

	new = lst_new((*arr)[index], index);
	if (new)
	{
		if (!*head)
		{
			new->next = new;
			new->prev = new;
			*head = new;
			return ;
		}
		(*head)->prev->next = new;
		new->prev = (*head)->prev;
		new->next = *head;
		(*head)->prev = new;
	}
	else
	{
		ft_putstr_fd("Malloc error\n", 2);
		free_normal_arr((void **)(arr));
		lst_clear(head);
	}
}

void	lst_clear(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*head)
		exit(0);
	if (lst_size(*head) == 1)
	{
		free(*head);
		exit(0);
	}
	tmp = *head;
	last = (*head)->prev;
	while (tmp->next != last)
	{
		tmp = tmp->next;
		free(*head);
		*head = tmp;
	}
	free(last);
	free(*head);
	*head = NULL;
}

int	lst_size(t_stack *head)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = head;
	if (!head)
		return (0);
	while (tmp->next != head)
	{
		i++;
		tmp = tmp->next;
	}
	i++;
	return (i);
}
