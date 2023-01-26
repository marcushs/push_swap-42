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
	t_stack	*new;

	new = lst_new(nb);
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
