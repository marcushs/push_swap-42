#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <stdio.h>

int	find_index(t_stack *head, long nb)
{
	t_stack	*tmp;

	tmp = head;
	while (1)
	{
		if (tmp->nb == nb)
			return (tmp->index);
		if (tmp == head->prev)
			return (tmp->index);
		tmp = tmp->next;
	}
}

int	find_index_back(t_stack *head, long nb)
{
	t_stack	*last;
	int		i;

	last = head->prev;
	i = 1;
	while (1)
	{
		if (last->nb == nb)
			return (i);
		if (last == head)
			return (i);
		i++;
		last = last->prev;
	}
}

int	find_target_index_b(t_stack *b, long push_nb)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (push_nb > b->nb && push_nb < b->prev->nb)
		return (0);
	else if (push_nb > find_max(&b) || push_nb < find_min(&b))
		i = find_max_index(&b);
	else
	{
		tmp = b->next;
		while (b->nb < push_nb || tmp->nb > push_nb)
		{
			b = b->next;
			tmp = b->next;
			i++;
		}
	}
	return (i);
}

int	find_target_index_a(t_stack *a, long push_nb)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (push_nb < a->nb && push_nb > a->prev->nb)
		return (0);
	else if (push_nb > find_max(&a) || push_nb < find_min(&a))
		i = find_min_index(&a);
	else
	{
		tmp = a->next;
		while (a->nb > push_nb || tmp->nb < push_nb)
		{
			a = a->next;
			tmp = a->next;
			i++;
		}
	}
	return (i);
}