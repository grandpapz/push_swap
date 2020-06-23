/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 14:03:20 by lelida            #+#    #+#             */
/*   Updated: 2020/06/23 14:05:03 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void		push(t_stack *from, t_stack *to, char c)
{
	to->stack[to->len] = from->stack[from->len - 1];
	from->stack[from->len - 1] = 0;
	to->len++;
	from->len--;
	if (c == 'a')
		ft_printf("pa\n");
	if (c == 'b')
		ft_printf("pb\n");
}

void		ss(t_ms *ms)
{
	int tmp;

	tmp = ms->a->stack[ms->a->len - 1];
	ms->a->stack[ms->a->len - 1] = ms->a->stack[ms->a->len - 2];
	ms->a->stack[ms->a->len - 2] = tmp;
	tmp = ms->b->stack[ms->b->len - 1];
	ms->b->stack[ms->b->len - 1] = ms->b->stack[ms->b->len - 2];
	ms->b->stack[ms->b->len - 2] = tmp;
	ft_printf("ss\n");
}

void		swap(t_ms *ms, char c)
{
	int tmp;

	if (c == 'a')
	{
		if (ms->b->len > 1 && ms->b->stack[ms->b->len - 2] &&
				ms->b->stack[ms->b->len - 1] < ms->b->stack[ms->b->len - 2])
			ss(ms);
		else
		{
			tmp = ms->a->stack[ms->a->len - 1];
			ms->a->stack[ms->a->len - 1] = ms->a->stack[ms->a->len - 2];
			ms->a->stack[ms->a->len - 2] = tmp;
			ft_printf("sa\n");
		}
	}
	if (c == 'b')
	{
		tmp = ms->b->stack[ms->b->len - 1];
		ms->b->stack[ms->b->len - 1] = ms->b->stack[ms->b->len - 2];
		ms->b->stack[ms->b->len - 2] = tmp;
		ft_printf("sb\n");
	}
}

void		rotate(t_stack *array, char c)
{
	int i;
	int tmp;

	i = array->len;
	tmp = array->stack[array->len - 1];
	while (i > 0)
	{
		array->stack[i - 1] = array->stack[i - 2];
		i--;
	}
	array->stack[i] = tmp;
	if (c == 'a')
		ft_printf("ra\n");
	if (c == 'b')
		ft_printf("rb\n");
}

void		revrot(t_stack *array, char c)
{
	int i;
	int tmp;

	i = 0;
	tmp = array->stack[0];
	while (i < array->len - 1)
	{
		array->stack[i] = array->stack[i + 1];
		i++;
	}
	array->stack[i] = tmp;
	if (c == 'a')
		ft_printf("rra\n");
	if (c == 'b')
		ft_printf("rrb\n");
}
