#include "../includes/libft.h"
#include "../includes/push_swap.h"

static void	ft_rrotate(t_stack **head)
{
	if (!*head || (*head)->next == *head)
		return ;
	*head = (*head)->prev;
	update_index(head, lst_size(*head));
}

void	ft_rra(t_stack **a)
{
	ft_rrotate(a);
	ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_stack **b)
{
	ft_rrotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_rrotate(a);
	ft_rrotate(b);
	ft_putstr_fd("rrr\n", 1);
}
