#include "../../includes/push_swap.h"

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
