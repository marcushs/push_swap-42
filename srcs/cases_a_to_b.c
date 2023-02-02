#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <stdio.h>

int	ft_count_rarb(t_stack *a, t_stack *b, long nb)
{
	int		i;

	i = find_target_index_b(b, nb);
	if (i < find_index(a, nb))
		i = find_index(a, nb);
	return (i);
}

int	ft_count_rrarrb(t_stack *a, t_stack *b, long nb)
{
	int	i;

	i = 0;
	if (find_target_index_b(b, nb))
		i = find_index_back(b, nb);
	if (i < find_index_back(a, nb) && find_index(a, nb))
		i = find_index_back(a, nb);
	return (i);
}

int	ft_count_rrarb(t_stack *a, t_stack *b, long nb)
{
	int		i;

	i = 0;
	if (find_index(a, nb))
		i = find_index_back(a, nb);
	i = find_target_index_b(b, nb) + i;
	return (i);
}

int	ft_count_rarrb(t_stack *a, t_stack *b, long nb)
{
	int	i;

	i = 0;
	if (find_target_index_b(b, nb))
		i = find_index_back(b, nb);
	i = find_index(a, nb) + i;
	return (i);
}
