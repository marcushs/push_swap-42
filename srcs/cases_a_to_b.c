#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <stdio.h>

int	ft_case_rarb(t_stack *a, t_stack *b, long nb)
{
	int		i;

	i = find_index_b(b, nb);
	if (i < find_index(a, nb))
		i = find_index(a, nb);
	return (i);
}

int	ft_case_rrarrb(t_stack *a, t_stack *b, long nb)
{
	int	i;

	i = 0;
	if (find_index_b(b, nb))
		i = lst_size(b) - find_index_b(b, nb);
	if ((i < (lst_size(a) - find_index(a, nb))) && find_index(a, nb))
		i = lst_size(a) - find_index(a, nb);
	return (i);
}

int	ft_case_rrarb(t_stack *a, t_stack *b, long nb)
{
	int		i;

	i = 0;
	if (find_index(a, nb))
		i = lst_size(a) - find_index(a, nb);
	i = find_index_b(b, nb) + i;
	return (i);
}

int	ft_case_rarrb(t_stack *a, t_stack *b, long nb)
{
	int	i;

	i = 0;
	if (find_index_b(b, nb))
		i = lst_size(b) - find_index_b(b, nb);
	i = find_index(a, nb) + i;
	return (i);
}
