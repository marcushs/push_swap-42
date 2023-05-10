/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:59:30 by hleung            #+#    #+#             */
/*   Updated: 2023/05/10 15:53:09 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	do_ops(char *line, t_stack **a, t_stack **b)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		ft_sa(a, 'c');
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		ft_sb(b, 'c');
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ft_ss(a, b, 'c');
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ft_ra(a, 'c');
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		ft_rb(b, 'c');
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		ft_rr(a, b, 'c');
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		ft_rra(a, 'c');
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		ft_rrb(b, 'c');
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		ft_rrr(a, b, 'c');
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		ft_pa(b, a, 'c');
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		ft_pb(a, b, 'c');
	else
		ft_putstr_fd("Error\n", 1);
}

void	apply_ops(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line && line[0] != '\n')
	{
		do_ops(line, a, b);
		free(line);
		line = get_next_line(0);
	}
	free(line);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		exit(0);
	if (argc == 2)
	{
		a = check_1arg(argv[1]);
		apply_ops(&a, &b);
	}
	if (argc > 2)
	{
		a = check_args(argc, argv);
		apply_ops(&a, &b);
	}
	if (!is_sorted(&a) || b)
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	lst_clear(&a);
	return (0);
}
