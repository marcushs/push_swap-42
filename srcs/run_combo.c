#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <stdio.h>

int	ft_run_rarb(t_stack **a, t_stack **b, long nb, char c)
{
	if (c == 'a')
	{
		while ((*a)->nb != nb && find_target_index_b(*b, nb) > 0)
			ft_rr(a, b);
		while ((*a)->nb != nb)
			ft_ra(a);
		while (find_target_index_b(*b, nb) > 0)
			ft_rb(b);
		ft_pb(a, b);
	}
	else
	{
		while ((*b)->nb != nb && find_target_index_a(*a, nb) > 0)
			ft_rr(a, b);
		while ((*b)->nb != nb)
			ft_rb(b);
		while (find_target_index_a(*a, nb) > 0)
			ft_ra(a);
		ft_pa(b, a);
	}
	return (-1);
}

int	ft_run_rrarrb(t_stack **a, t_stack **b, long nb, char c)
{
	if (c == 'a')
	{
		while ((*a)->nb != nb && find_target_index_b(*b, nb) > 0)
			ft_rrr(a, b);
		while ((*a)->nb != nb)
			ft_rra(a);
		while (find_target_index_b(*b, nb) > 0)
			ft_rrb(b);
		ft_pb(a, b);
	}
	else
	{
		while ((*b)->nb != nb && find_target_index_a(*a, nb) > 0)
			ft_rrr(a, b);
		while ((*b)->nb != nb)
			ft_rrb(b);
		while (find_target_index_a(*a, nb) > 0)
			ft_rra(a);
		ft_pa(b, a);
	}
	return (-1);
}

int	ft_run_rrarb(t_stack **a, t_stack **b, long nb, char c)
{
	if (c == 'a')
	{
		while ((*a)->nb != nb)
			ft_rra(a);
		while (find_target_index_b(*b, nb) > 0)
			ft_rb(b);
		ft_pb(a, b);
	}
	else
	{
		while ((*b)->nb != nb)
			ft_rb(b);
		while (find_target_index_a(*a, nb) > 0)
			ft_rra(a);
		ft_pa(b, a);
	}
	return (-1);	
}

int	ft_run_rarrb(t_stack **a, t_stack **b, long nb, char c)
{
	if (c == 'a')
	{
		while ((*a)->nb != nb)
			ft_ra(a);
		while (find_target_index_b(*b, nb) > 0)
			ft_rrb(b);
		ft_pb(a, b);
	}
	else
	{
		while ((*b)->nb != nb)
			ft_rrb(b);
		while (find_target_index_a(*a, nb) > 0)
			ft_ra(a);
		ft_pa(b, a);
	}
	return (-1);	
}
