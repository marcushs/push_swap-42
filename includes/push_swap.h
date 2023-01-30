/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcus <marcus@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:38:51 by hleung            #+#    #+#             */
/*   Updated: 2023/01/30 15:06:31 by marcus           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define ARG_ERROR "ERROR\n"
# include <stdlib.h>

typedef struct s_stack
{
	long	nb;
	int		index;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

//check
t_stack	*check_1arg(char *argv);
t_stack	*check_args(int argc, char **argv);
//error
int		check_char(char *str);
int		check_char_strs(char **strings);
int		check_double(long *arr, int count);
//parse
t_stack	*arr_to_lst(long *arr, int size);
//dcll
t_stack	*lst_new(long nb, int index);
void	lst_add_front(t_stack **head, long nb);
void	lst_add_back(t_stack **head, long nb, int index);
void	lst_clear(t_stack **head);
void	lst_print(t_stack *head);
int		lst_size(t_stack *head);
//free
void	print_message_exit(void);
void	free_and_exit(void **arr, void (*f)(void **));
void	free_error_exit(void **arr, void (*f)(void **));
void	free_normal_arr(void **arr);
void	free_2d_array(void **arr);
//operations utils
void	update_index(t_stack **head, int size);
//operations
//swap
void	ft_sa(t_stack **a);
void	ft_sb(t_stack **b);
void	ft_ss(t_stack **a, t_stack **b);
//rotate
void	ft_ra(t_stack **a);
void	ft_rb(t_stack **b);
void	ft_rr(t_stack **a, t_stack **b);
//rrotate
void	ft_rra(t_stack **a);
void	ft_rrb(t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);
//push
void	ft_pa(t_stack **b, t_stack **a);
void	ft_pb(t_stack **a, t_stack **b);
#endif
