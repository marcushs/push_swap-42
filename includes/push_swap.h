/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:38:51 by hleung            #+#    #+#             */
/*   Updated: 2023/01/26 14:50:43 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define ARG_ERROR "ERROR\n"
# include <stdlib.h>

typedef struct s_stack
{
	long	nb;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

//check
void	check_1arg(char *argv);
void	check_args(int argc, char **argv);
//error
void	check_char(char *str);
void	check_char_strs(char **strings);
int		check_double(long *arr, int count);
//free
void	print_message_exit(void);
void	free_and_exit(void **arr, void (*f)(void **));
void	free_normal_arr(void **arr);
void	free_2d_array(void **arr);
//parse
char	**parse_1arg_to_strings(char *argv);
int	count_element(char *arg);
t_stack	*parse_args(int argc, char **argv);
int	check_double_lst(t_stack *a);


//dcll
t_stack	*lst_new(long nb);
void	lst_add_front(t_stack **head, long nb);
void	lst_add_back(t_stack **head, long nb);
void	lst_clear(t_stack **head);
void	lst_print(t_stack *head);
#endif
