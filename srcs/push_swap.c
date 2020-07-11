/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 13:30:53 by lelida            #+#    #+#             */
/*   Updated: 2020/07/09 13:30:55 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int ac, char *av[])
{
	t_stack		stack;
	int			ret;

	ret = 0;
	stack.print = 1;
	if (ac < 2)
		print_error();
	av += 1;
	if ((ret = init_stack(&stack, av)))
		print_error();
	sort_stack(&stack);
	free_stack(&stack);
	return (ret);
}
