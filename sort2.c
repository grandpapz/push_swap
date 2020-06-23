/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 14:52:58 by lelida            #+#    #+#             */
/*   Updated: 2020/06/23 14:53:51 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void		top_min(t_ms *ms, t_stack *stack, char c)
{
	if (stack->len == 3)
	{
		revrot(stack, c);
		swap(ms, c);
	}
	else
	{
		rotate(stack, c);
		swap(ms, c);
		revrot(stack, c);
	}
}

static void		top_mid(t_ms *ms, t_stack *stack, char c)
{
	if (stack->len == 3)
	{
		if (stack->stack[stack->len - 3] == stack->min)
			revrot(stack, c);
		else
			swap(ms, c);
	}
	else
	{
		if (stack->stack[stack->len - 3] == stack->min)
		{
			rotate(stack, c);
			swap(ms, c);
			revrot(stack, c);
		}
		swap(ms, c);
	}
}

static void		top_max(t_ms *ms, t_stack *stack, char c)
{
	if (stack->len == 3)
	{
		if (stack->stack[stack->len - 2] == stack->min)
			rotate(stack, c);
		else
		{
			swap(ms, c);
			revrot(stack, c);
		}
	}
	else
	{
		swap(ms, c);
		if (stack->stack[stack->len - 1] == stack->min)
			top_min(ms, stack, c);
		else
			top_mid(ms, stack, c);
	}
}

void			sort_three(t_ms *ms, t_stack *stack, char c)
{
	if (is_sorted(stack, 3))
		return ;
	find_min_max(stack, 3);
	if (stack->stack[stack->len - 1] == stack->max)
		top_max(ms, stack, c);
	else if (stack->stack[stack->len - 1] == stack->min)
		top_min(ms, stack, c);
	else
		top_mid(ms, stack, c);
}
