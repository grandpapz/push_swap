/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 14:36:33 by lelida            #+#    #+#             */
/*   Updated: 2020/06/23 14:37:10 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void		top_max(t_ms *ms, t_stack *stack, char c)
{
	rotate(stack, c);
	swap(ms, c);
	revrot(stack, c);
}

static void		top_mid(t_ms *ms, t_stack *stack, char c)
{
	if (stack->len == 3 && stack->stack[stack->len - 2] == stack->min)
		revrot(stack, c);
	else
	{
		if (stack->stack[stack->len - 2] == stack->min)
		{
			rotate(stack, c);
			swap(ms, c);
			revrot(stack, c);
		}
		swap(ms, c);
	}
}

static void		top_min(t_ms *ms, t_stack *stack, char c)
{
	swap(ms, c);
	if (stack->stack[stack->len - 1] == stack->max)
		top_max(ms, stack, c);
	else
		top_mid(ms, stack, c);
}

void			sort_three_b(t_ms *ms, t_stack *stack, char c)
{
	if (is_rev_sorted(stack, 3))
		return ;
	find_min_max(stack, 3);
	if (stack->stack[stack->len - 1] == stack->max)
		top_max(ms, stack, c);
	else if (stack->stack[stack->len - 1] == stack->min)
		top_min(ms, stack, c);
	else
		top_mid(ms, stack, c);
}
