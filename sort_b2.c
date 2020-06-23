/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 14:55:08 by lelida            #+#    #+#             */
/*   Updated: 2020/06/23 14:56:41 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void		return_btoa(t_ms *ms, int len)
{
	while (len > 0)
	{
		push(ms->b, ms->a, 'a');
		len--;
	}
}

int				is_rev_sorted(t_stack *stack, int len)
{
	int i;

	i = stack->len - 1;
	while (i > 0 && len > 1)
	{
		if (stack->stack[i] < stack->stack[i - 1])
			return (0);
		len--;
		i--;
	}
	return (1);
}

void			mini_sort_b(t_ms *ms, int part)
{
	if (part == 1 || part == 2 || part == 3)
	{
		if (part == 2)
			if (is_sorted(ms->b, 2))
				swap(ms, 'b');
		if (part == 3)
			sort_three_b(ms, ms->b, 'b');
	}
	return_btoa(ms, part);
}
