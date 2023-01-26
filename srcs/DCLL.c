/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DCLL.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:46:54 by hleung            #+#    #+#             */
/*   Updated: 2023/01/26 17:02:06 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <stdio.h>

t_stack	*lst_new(long nb)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		//need free here
		return (NULL);
	new->nb = nb;
	new->next = new;
	new->prev = new;
	return (new);
} 

void	lst_traverse(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp->next != head)
		tmp = tmp->next;
}

void	lst_traverse_back(t_stack *head)
{
	t_stack	*tmp;

	tmp = head->prev;
	while (tmp != head)
		tmp = tmp->prev;
}

void	lst_add_front(t_stack **head, long nb)
{
	t_stack	*new;

	new = lst_new(nb);
	//if (!new)
	if (!*head)
	{
		*head = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	(*head)->prev->next = new;
	new->prev = (*head)->prev;
	new->next = *head;
	(*head)->prev = new;
	(*head) = new;
}

void	lst_add_back(t_stack **head, long nb)
{
	t_stack *new;

	new = lst_new(nb);
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
}

void	lst_clear(t_stack **head)
{
	t_stack	*tmp;

	if (!*head)
		exit(0);
	tmp = *head;
	while (tmp->next != *head)
	{
		tmp = tmp->next;
		free(*head);
		*head = tmp;
	}
}

void	lst_print(t_stack *head)
{
	t_stack	*tmp;
	
	tmp = head;
	if (!head)
		return ;
	do
	{
		printf("%ld ", tmp->nb);
		tmp = tmp->next;
	} while (tmp != head);
}