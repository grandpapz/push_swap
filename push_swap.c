/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 14:47:58 by lelida            #+#    #+#             */
/*   Updated: 2020/06/27 18:40:05 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	main(int ac, char **av)
{
	t_ms	*ms;
	int		i;

	if (ac != 2)
	{
		ft_printf("Usage: ./push_swap [integer array]\n");
		exit(0);
	}
	av++;
	ac--;
	ms = (t_ms *)malloc(sizeof(t_ms));
	if (ac == 1)
		av = arg_splt(&ac, &av);
	init_stacks(ms, ac);
	create_stack(ac, av, ms);
	if (ms->a->len <= 7)
		small_stack_sort(ms);
	else
		devide_stack(ms);
	free_ms(ms);
	i = -1;
	while (av[++i])
		free(av[i]);
	free(av);
	return (0);
}
