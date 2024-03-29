/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:38:51 by hleung            #+#    #+#             */
/*   Updated: 2023/05/10 14:27:13 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define ARG_ERROR "Error\n"
# define BUFFER_SIZE 1
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	long			nb;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

//check
int		count_elements(char *arg);
t_stack	*check_1arg(char *argv);
t_stack	*check_args(int argc, char **argv);
//error
int		check_char(char *str);
int		check_char_strs(char **strings);
int		check_length(char *s);
int		check_double(long *arr, int count);
//parse
t_stack	*arr_to_lst(long *arr, int size);
//dcll
t_stack	*lst_new(long nb, int index);
void	lst_add_front(t_stack **head, long nb);
void	lst_add_back(t_stack **head, long **arr, int index);
void	lst_clear(t_stack **head);
void	lst_print(t_stack *head);
int		lst_size(t_stack *head);
//free
void	print_message_exit(void);
void	free_error_exit(void **arr, void (*f)(void **));
void	free_normal_arr(void **arr);
void	free_2d_array(void **arr);
void	free_2d_error_exit(void **strs, void **arr);
//operations utils
void	update_index(t_stack **head, int size);
//operations
//swap
void	ft_sa(t_stack **a, char c);
void	ft_sb(t_stack **b, char c);
void	ft_ss(t_stack **a, t_stack **b, char c);
//rotate
void	ft_ra(t_stack **a, char c);
void	ft_rb(t_stack **b, char c);
void	ft_rr(t_stack **a, t_stack **b, char c);
//rrotate
void	ft_rra(t_stack **a, char c);
void	ft_rrb(t_stack **b, char c);
void	ft_rrr(t_stack **a, t_stack **b, char c);
//push
void	ft_pa(t_stack **b, t_stack **a, char c);
void	ft_pb(t_stack **a, t_stack **b, char c);
//solve
void	solve(t_stack **a);
void	solve_3(t_stack **a);
void	solve_5_or_under(t_stack **a, t_stack **b);
//solve utils
long	find_max(t_stack **head);
long	find_min(t_stack **head);
int		find_max_index(t_stack **head);
int		find_min_index(t_stack **head);
int		is_sorted(t_stack **head);
int		find_target_index_b(t_stack *b, long push_nb);
int		find_target_index_a(t_stack *a, long push_nb);
int		find_index(t_stack *head, long nb);
int		find_index_back(t_stack *head, long nb);
//smart rotate cases
//from a to b
int		ft_count_rarb(t_stack *a, t_stack *b, long nb);
int		ft_count_rrarrb(t_stack *a, t_stack *b, long nb);
int		ft_count_rrarb(t_stack *a, t_stack *b, long nb);
int		ft_count_rarrb(t_stack *a, t_stack *b, long nb);
//from b to a
int		ft_count_rarb_a(t_stack *a, t_stack *b, long nb);
int		ft_count_rrarrb_a(t_stack *a, t_stack *b, long nb);
int		ft_count_rrarb_a(t_stack *a, t_stack *b, long nb);
int		ft_count_rarrb_a(t_stack *a, t_stack *b, long nb);
//best rotate comb
int		best_rotate_comb_a_to_b(t_stack *a, t_stack *b);
int		best_rotate_comb_b_to_a(t_stack *a, t_stack *b);
//run cases
int		ft_run_rarb(t_stack **a, t_stack **b, long nb, char c);
int		ft_run_rrarrb(t_stack **a, t_stack **b, long nb, char c);
int		ft_run_rrarb(t_stack **a, t_stack **b, long nb, char c);
int		ft_run_rarrb(t_stack **a, t_stack **b, long nb, char c);
//gnl && gnl_utils
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strchr_gnl(char *s, int c);
char	*get_next_line(int fd);
#endif
