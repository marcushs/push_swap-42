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
