/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcus <marcus@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:38:51 by hleung            #+#    #+#             */
/*   Updated: 2023/01/25 15:35:59 by marcus           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define ARG_ERROR "ERROR\n"
# include <stdlib.h>

typedef struct s_stack
{
	long	nb;
	t_stack	*next;
	t_stack	*prev;
}				t_stack;

//error
int		check_double(long *arr, int count);
//free
void	print_message_exit(void);
void	free_and_exit(void **arr, void (*f)(void **));
void	free_normal_arr(void **arr);
void	free_2d_array(void **arr);
//parse
char	**parse_1arg_to_strings(char *argv);
int	count_element(char *arg);
#endif
