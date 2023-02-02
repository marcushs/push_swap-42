#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <stdio.h>

static void	solve_2(t_stack **a)
{
	if ((*a)->nb > (*a)->next->nb)
		ft_sa(a);
}

void	solve_3(t_stack **a)
{
	if (is_sorted(a))
		return ;
	if (find_min_index(a) == 2)
	{
		ft_rra(a);
		if (is_sorted(a))
			return ;
	}
	if (find_min_index(a) == 1)
	{
		ft_sa(a);
		if (is_sorted(a))
			return ;
	}
	if (find_min_index(a) == 0)
	{
		ft_rra(a);
		ft_sa(a);
	}
}

static void	solve_4(t_stack **a, t_stack **b)
{
	if (is_sorted(a))
		return ;
	if (find_min_index(a) <= 1)
	{
		while (find_min_index(a) > 0)
			ft_sa(a);
	}
	else
	{
		while (find_min_index(a) > 0)
			ft_rra(a);
	}
	ft_pb(a, b);
	solve_3(a);
	ft_pa(b, a);
}

static void	solve_5(t_stack **a, t_stack **b)
{
	if (is_sorted(a))
		return ;
	if (find_max_index(a) == 2)
	{
		while (find_max_index(a) > 0)
			ft_ra(a);
	}
	else if (find_max_index(a) < 2)
	{
		while (find_max_index(a) > 0)
			ft_sa(a);
	}
	else
	{
		while (find_max_index(a) > 0)
			ft_rra(a);
	}
	ft_pb(a, b);
	solve_4(a, b);
	ft_pa(b, a);
	ft_ra(a);
}

void	solve_5_or_under(t_stack **a, t_stack **b)
{
	int	size;

	size = lst_size(*a);
	if (is_sorted(a))
		return ;
	if (size == 2)
		solve_2(a);
	else if (size == 3)
		solve_3(a);
	else if (size == 4)
		solve_4(a, b);
	else
		solve_5(a, b);
}
