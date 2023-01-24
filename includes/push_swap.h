/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcus <marcus@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:38:51 by hleung            #+#    #+#             */
/*   Updated: 2023/01/24 20:12:29 by marcus           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define ARG_ERROR "ERROR\n"
# include <stdlib.h>

//error
void	print_message_exit(void);
void	check_char(char **strings);
int		check_double(long *arr, int count);
//free
void	free_2d_array(void **arr);
//parse
char	**parse_arg_to_strings(char *argv);
long	*strings_to_arr(char **strs, int count);
#endif
