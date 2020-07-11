/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 13:31:27 by lelida            #+#    #+#             */
/*   Updated: 2020/07/09 13:38:19 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	print_operation(t_stack *stack, const char *str, const char let)
{
	if (stack->print)
	{
		ft_putstr(str);
		let ? ft_putchar(let) : 0;
		ft_putchar('\n');
	}
}

int		get_median(t_stack *stack, int s, int num)
{
	t_node	*lst;
	int		max;
	int		min;
	int		i;

	lst = stack->stack[s]->head;
	max = lst->data;
	min = lst->data;
	i = -1;
	while (++i < stack->push[s][num])
	{
		(max < lst->data) ? max = lst->data : 0;
		(min > lst->data) ? min = lst->data : 0;
		lst = lst->next;
	}
	return ((max + min) / 2);
}

int		is_substack(t_stack *stack, int med, int s)
{
	t_node	*tmp;
	int		ret;
	int		i;

	ret = 0;
	i = -1;
	tmp = stack->stack[s]->head;
	if (s == A)
		while (++i < stack->push[s][stack->num_a])
		{
			if (tmp->data <= med)
				ret++;
			tmp = tmp->next;
		}
	else
		while (++i < stack->push[s][stack->num_b])
		{
			if (tmp->data >= med)
				ret++;
			tmp = tmp->next;
		}
	return (ret);
}

int		issort(t_linklist *stack)
{
	t_node	*tmp;

	tmp = stack->head;
	if (stack->letter == 'a')
	{
		while (tmp->next && tmp->data < tmp->next->data)
			tmp = tmp->next;
	}
	else
		while (tmp->next && tmp->data > tmp->next->data)
			tmp = tmp->next;
	return (!(stack->letter == 'a' ? tmp->next : tmp->prev));
}
