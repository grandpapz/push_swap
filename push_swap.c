/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 14:47:58 by lelida            #+#    #+#             */
/*   Updated: 2020/06/29 16:23:02 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int		main(int ac, char *av[])
{
	t_ms	*ms;
	char	**str;

	str = NULL;
	if (!av[1])
	{
		ft_printf("Usage: ./push_swap [integer array]\n");
		exit(0);
	}
	av++;
	ac--;
	ms = (t_ms *)malloc(sizeof(t_ms));
	if (ac >= 1)
		str = arg_splt(ac, av);
	init_stacks(ms, ac);
	create_stack(str, ms);
	if (ms->a->len <= 7)
		small_stack_sort(ms);
	else
		devide_stack(ms);
	free_str(str);
	free_ms(ms);
	return (0);
}
