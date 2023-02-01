#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <stdio.h>

int	ft_case_rarb_a(t_stack *a, t_stack *b, long nb)
{
	int	i;

	i = find_index_a(a, nb);
	if (i < find_index(b, nb))
		i = find_index(b, nb);
	return (i);
}

int	ft_case_rrarrb_a(t_stack *a, t_stack *b, long nb)
{
	int	i;

	i = 0;
	if (find_index_a(a, nb))
		i = lst_size(a) - find_index_a(a, nb);
	if ((i < (lst_size(b) - find_index(b, nb))) && find_index(b, nb))
		i = lst_size(b) - find_index(b, nb);
	return (i);
}

int	ft_case_rrarb_a(t_stack *a, t_stack *b, long nb)
{
	int	i;

	i = 0;
	if (find_index_a(a, nb))
		i = lst_size(a) - find_index_a(a, nb);
	i = i + find_index(b, nb);
	return (i);
}

int	ft_case_rarrb_a(t_stack *a, t_stack *b, long nb)
{
	int	i;

	i = 0;
	if (find_index(b, nb))
		i = lst_size(b) - find_index(b, nb);
	i = i + find_index_a(a, nb);
	return (i);
}
