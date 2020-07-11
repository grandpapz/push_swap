/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 13:31:15 by lelida            #+#    #+#             */
/*   Updated: 2020/07/09 13:31:17 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	tiny_sort(t_linklist *lst, t_stack *stack)
{
	while (!issort(lst))
	{
		if (lst->head->data > lst->head->next->data)
			swap(lst, stack);
		else if (lst->head->next->data > lst->tail->data)
			revrotate(lst, stack);
		else
			rotate(lst, stack);
	}
}

void		mini_sort(t_linklist *lst, t_stack *stack)
{
	t_linklist	*dst;
	int			p;

	p = 0;
	dst = stack->stack[B];
	while (!issort(lst))
	{
		if (lst->head->data > lst->head->next->data)
		{
			if (dst->size > 1 && dst->head->data < dst->head->next->data && !p)
				doub_opt(stack, "ss", swap);
			else
				swap(lst, stack);
		}
		else if (++p)
			push(lst, dst, stack);
	}
	if (p)
	{
		while (p--)
			push(dst, lst, stack);
		mini_sort(lst, stack);
	}
}

void		quick_sort(t_stack *stack)
{
	if (!issort(stack->stack[A]))
		split_stack(stack, get_median(stack, A, stack->num_a));
	else if (stack->stack[B]->size > 0)
		merger_stack(stack, get_median(stack, B, stack->num_b));
	else
		return ;
	quick_sort(stack);
}

void		sort_stack(t_stack *stack)
{
	if (stack->stack[A]->size <= 3)
		tiny_sort(stack->stack[A], stack);
	else if (stack->push[A][stack->num_a] <= 3)
		mini_sort(stack->stack[A], stack);
	else
		quick_sort(stack);
}
