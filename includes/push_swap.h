/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcus <marcus@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:38:51 by hleung            #+#    #+#             */
/*   Updated: 2023/01/29 18:41:13 by marcus           ###   ########lyon.fr   */
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
//instructions
void	ft_sa(t_stack **head);
void	ft_ra(t_stack **head);
void	ft_rra(t_stack **head);
#endif
