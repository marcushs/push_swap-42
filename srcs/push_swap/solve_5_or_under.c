#include "../../includes/push_swap.h"

static void	solve_2(t_stack **a)
{
	if ((*a)->nb > (*a)->next->nb)
		ft_sa(a, 'p');
}

void	solve_3(t_stack **a)
{
	if (is_sorted(a))
		return ;
	if (find_min_index(a) == 2)
	{
		ft_rra(a, 'p');
		if (is_sorted(a))
			return ;
	}
	if (find_min_index(a) == 1)
	{
		ft_sa(a, 'p');
		if (is_sorted(a))
			return ;
	}
	if (find_min_index(a) == 0)
	{
		ft_rra(a, 'p');
		ft_sa(a, 'p');
	}
}

static void	solve_4(t_stack **a, t_stack **b)
{
	if (is_sorted(a))
		return ;
	if (find_min_index(a) <= 1)
	{
		while (find_min_index(a) > 0)
			ft_sa(a, 'p');
	}
	else
	{
		while (find_min_index(a) > 0)
			ft_rra(a, 'p');
	}
	ft_pb(a, b, 'p');
	solve_3(a);
	ft_pa(b, a, 'p');
}

static void	solve_5(t_stack **a, t_stack **b)
{
	if (is_sorted(a))
		return ;
	if (find_max_index(a) == 2)
	{
		while (find_max_index(a) > 0)
			ft_ra(a, 'p');
	}
	else if (find_max_index(a) < 2)
	{
		while (find_max_index(a) > 0)
			ft_sa(a, 'p');
	}
	else
	{
		while (find_max_index(a) > 0)
			ft_rra(a, 'p');
	}
	ft_pb(a, b, 'p');
	solve_4(a, b);
	ft_pa(b, a, 'p');
	ft_ra(a, 'p');
}

void	solve_5_or_under(t_stack **a, t_stack **b)
{
	int	size;

	size = lst_size(*a);
	if (size <= 1 || is_sorted(a))
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
