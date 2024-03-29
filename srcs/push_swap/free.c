/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:44:14 by hleung            #+#    #+#             */
/*   Updated: 2023/02/08 10:02:49 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_message_exit(void)
{
	ft_putstr_fd(ARG_ERROR, 2);
	exit(0);
}

void	free_error_exit(void **arr, void (*f)(void **))
{
	(*f)(arr);
	print_message_exit();
}

void	free_normal_arr(void **arr)
{
	free(*arr);
	*arr = NULL;
}

void	free_2d_array(void **arr)
{
	int	i;

	i = -1;
	while (((void **)*arr)[++i])
	{
		free(((void **)*arr)[i]);
		((void **)*arr)[i] = NULL;
	}
	free(*arr);
	*arr = NULL;
}

void	free_2d_error_exit(void **strs, void **arr)
{
	free_2d_array(strs);
	free_normal_arr(arr);
	print_message_exit();
}
