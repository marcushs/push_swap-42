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
		i = best_rotate_comb_a_to_b(*a, *b);
		while (i >= 0)
		{
			if (i == ft_count_rarb(*a, *b, tmp->nb))
				i = ft_run_rarb(a, b, tmp->nb, 'a');
			else if (i == ft_count_rrarrb(*a, *b, tmp->nb))
				i = ft_run_rrarrb(a, b, tmp->nb, 'a');
			else if (i == ft_count_rrarb(*a, *b, tmp->nb))
				i = ft_run_rrarb(a, b, tmp->nb, 'a');
			else if (i == ft_count_rarrb(*a, *b, tmp->nb))
				i = ft_run_rarrb(a, b, tmp->nb, 'a');
			else
				tmp = tmp->next;
		}
	}
}

void	push_b_sort_3_a(t_stack **a, t_stack **b)
{
	if (lst_size(*a) > 3 && !is_sorted(a))
		ft_pb(a, b);
	if (lst_size(*a) > 3 && !is_sorted(a))
		ft_pb(a, b);
	if (lst_size(*a) > 3 && !is_sorted(a))
		smart_rotate_till_3_in_a(a, b);
	if (!is_sorted(a))
		solve_3(a);
}

void	push_back_a(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*tmp;

	while (*b)
	{
		printf("hello\n");
		tmp = *b;
		i = best_rotate_comb_b_to_a(*a, *b);
		while (i >= 0)
		{
			if (i == ft_count_rarb_a(*a, *b, tmp->nb))
				i = ft_run_rarb(a, b, tmp->nb, 'b');
			else if (i == ft_count_rrarrb_a(*a, *b, tmp->nb))
				i = ft_run_rrarrb(a, b, tmp->nb, 'b');
			else if (i == ft_count_rrarb_a(*a, *b, tmp->nb))
				i = ft_run_rrarb(a, b, tmp->nb, 'b');
			else if (i == ft_count_rarrb_a(*a, *b, tmp->nb))
				i = ft_run_rarrb(a, b, tmp->nb, 'b');
			else
				tmp = tmp->next;
		}
	}
}

void	solve_large(t_stack **a, t_stack **b)
{
	if (!is_sorted(a))
	{
		push_b_sort_3_a(a, b);
		printf("Stack a:\n");
		lst_print(*a);
		(!is_sorted(a) ? printf("NOT SORTED!\n") : printf("SORTED!\n"));
		printf("Stack b:\n");
		lst_print(*b);
		(!is_sorted(b) ? printf("NOT SORTED!\n") : printf("SORTED!\n"));
		push_back_a(a, b);
	}
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
	else
		solve_large(a, &b);
}
