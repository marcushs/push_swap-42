#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <stdio.h>

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
