/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_sort_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 14:31:10 by lelida            #+#    #+#             */
/*   Updated: 2020/06/23 14:32:29 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static int	ret_revsort_stack(t_ms *ms, int part)
{
	find_min_max(ms->b, part);
	while (part > 0 && ms->b->stack[ms->b->len - 1] == ms->b->max)
	{
		push(ms->b, ms->a, 'a');
		part--;
	}
	return (part);
}

int			ret_sorted_b(t_ms *ms, int part)
{
	int i;

	i = part;
	while (i > 1)
	{
		rotate(ms->b, 'b');
		i--;
	}
	while (i < part)
	{
		push(ms->b, ms->a, 'a');
		revrot(ms->b, 'b');
		i++;
	}
	push(ms->b, ms->a, 'a');
	return (0);
}

void		part_sort_b(t_ms *ms, int part)
{
	int c_part;

	c_part = 0;
	find_min_max(ms->b, part);
	part = ret_revsort_stack(ms, part);
	while (part > 3)
	{
		part = ret_revsort_stack(ms, part);
		if (is_sorted(ms->b, part))
			part = ret_revsort_stack(ms, part);
		c_part = push_top_b(ms, part);
		if (c_part <= 3)
			mini_sort(ms, part);
		else
			part_sort_a(ms, c_part);
		part -= c_part;
	}
	mini_sort_b(ms, part);
}
