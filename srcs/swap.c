#include "../includes/libft.h"
#include "../includes/push_swap.h"

static void	update_ptr_swap(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;
	
	if (!*head || (*head)->next == *head)
		return ;
	first = *head;
	second = (*head)->next;
	first->prev->next = second;
	second->prev = first->prev;
	second->next->prev = first;
	first->next = second->next;
	second->next = first;
	first->prev = second;
	*head = second;
}

static void	ft_swap(t_stack **head)
{
	int		size;

	if ((*head)->next == *head || !*head)
		return ;
	size = lst_size(*head);
	if (size == 2)
		*head = (*head)->next;
	else
		update_ptr_swap(head);
	update_index(head, size);
}

void	ft_sa(t_stack **a)
{
	ft_swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_stack **b)
{
	ft_swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_swap(a);
	ft_swap(b);
	ft_putstr_fd("ss\n", 1);
}
