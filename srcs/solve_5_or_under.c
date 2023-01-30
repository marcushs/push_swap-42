#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <stdio.h>

//works
void	solve_2(t_stack **a)
{
	if ((*a)->nb > (*a)->next->nb)
		ft_sa(a);
}
//works
void	solve_3(t_stack **a)
{
	if (find_min(a) == 2)
	{
		ft_rra(a);
		if (is_sorted(a))
			return ;
	}
	if (find_min(a) == 1)
	{
		ft_sa(a);
		if (is_sorted(a))
			return ;
	}
	if (find_min(a) == 0)
	{
		ft_rra(a);
		ft_sa(a);
	}
}

void	solve_5_or_under(t_stack **a)
{
	int	size;
	t_stack	*b;

	size = lst_size(a);
	if (is_sorted(a))
		return ;
	if (size == 2)
		solve_2(a);
	else if (size == 3)
		solve_3(a);
	else
	{
		while (lst_size(a) > 3)
			ft_pb(a, &b);
		solve_3(a);
	}
}
