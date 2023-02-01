#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <stdio.h>

int	find_index_b(t_stack *b, long push_nb)
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

int	find_index_a(t_stack *a, long push_nb)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (push_nb > a->nb && push_nb < a->prev->nb)
		return (0);
	else if (push_nb > find_max(&a) || push_nb < find_min(&a))
		i = find_min_index(&a);
	else
	{
		tmp = a->next;
		while (a->nb < push_nb || tmp->nb > push_nb)
		{
			a = a->next;
			tmp = a->next;
			i++;
		}
	}
	return (i);
}



void	smart_rotate_till_3_in_a(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*tmp;

	while (lst_size(*a) > 3 && !is_sorted(a))
	{
		tmp = *a;
		i = 
	}
}

void	push_b_sort_3_a(t_stack **a, t_stack **b)
{
	while (!is_sorted(a) && lst_size(*a) > 3)
		ft_pb(a, b);
	if (lst_size(*a) > 3 && !is_sorted(a))
		smart_rotate_till_3_in_a(a, b);
	if (!is_sorted(a))
		solve_3(a);
}

void	solve(t_stack **a)
{
	int	size;
	t_stack	*b;

	b = NULL;
	if (is_sorted(a) || !*a)
		return ;
	size = lst_size(*a);
	if (size <= 5 && !is_sorted(a))
		solve_5_or_under(a, &b);
	// else
	// 	solve_large(a, b);
}
