#include "../includes/libft.h"
#include "../includes/push_swap.h"

static void	ft_rotate(t_stack **head)
{
	if (!*head || (*head)->next == *head)
		return ;
	*head = (*head)->next;
	update_index(head, lst_size(*head));
}

void	ft_ra(t_stack **a)
{
	ft_rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_stack **b)
{
	ft_rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_putstr_fd("rr\n",1);
}

