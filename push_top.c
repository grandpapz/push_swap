/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 14:33:02 by lelida            #+#    #+#             */
/*   Updated: 2020/06/23 14:33:30 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static int	count_push_sum(t_ms *ms, int part, int mid)
{
	int counter;
	int i;

	counter = 0;
	i = ms->a->len - part;
	while (i < ms->a->len)
	{
		if (ms->a->stack[i] < mid)
			counter++;
		i++;
	}
	return (counter);
}

static void	push_back(t_ms *ms, int pb)
{
	int x;

	x = ms->a->len - pb;
	if (pb > x)
	{
		while (x > 0)
		{
			rotate(ms->a, 'a');
			x--;
		}
	}
	else
	{
		while (pb > 0)
		{
			revrot(ms->a, 'a');
			pb--;
		}
	}
}

int			push_top(t_ms *ms, int part)
{
	int mid;
	int p;
	int len;
	int pb;

	find_min_max(ms->a, part);
	mid = find_mid(ms->a->min, ms->a->max, part);
	len = count_push_sum(ms, part, mid);
	p = len;
	pb = 0;
	while (len > 0)
	{
		if (ms->a->stack[ms->a->len - 1] < mid)
		{
			push(ms->a, ms->b, 'b');
			len--;
		}
		else
		{
			rotate(ms->a, 'a');
			pb++;
		}
	}
	push_back(ms, pb);
	return (p);
}
