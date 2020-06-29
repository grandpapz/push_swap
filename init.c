/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 13:57:52 by lelida            #+#    #+#             */
/*   Updated: 2020/06/23 14:02:52 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void			free_ms(t_ms *ms)
{
	free(ms->a->stack);
	free(ms->b->stack);
	free(ms->a);
	free(ms->b);
	free(ms);
	ms = NULL;
}

int				validator(t_ms *ms, char *str, int i)
{
	if (!ft_isdigit(str[0]) && (is_sign(str[0] && !ft_isdigit(str[1]))))
		return (0);
	if (ft_atoi(str) < INT_MIN || ft_atoi(str) > INT_MAX)
		return (0);
	if (ft_atoi(str) == 0 && ft_strlen(str) > 1)
		return (0);
	while (i >= 0 && i <= ms->a->len)
	{
		if (ft_atoi(str) == ms->a->stack[i] && ft_atoi(str) != 0)
			return (0);
		i--;
	}
	return (1);
}

void			init_stacks(t_ms *ms, int ac)
{
	ms->a = (t_stack *)malloc(sizeof(t_stack));
	ms->b = (t_stack *)malloc(sizeof(t_stack));
	ms->a->stack = (int *)malloc(sizeof(int) * (ac));
	ms->b->stack = (int *)ft_memalloc(sizeof(int) * (ac));
	ms->b->len = 0;
}

void			find_min_max(t_stack *array, int range)
{
	int i;

	i = array->len - range;
	array->max = INT_MIN;
	array->min = INT_MAX;
	while (i < array->len)
	{
		if (array->stack[i] > array->max)
			array->max = array->stack[i];
		if (array->stack[i] < array->min)
			array->min = array->stack[i];
		i++;
	}
}

void			create_stack(char **av, t_ms *ms)
{
	int i;
	int top;

	i = 0;
	while (av[i])
		i++;
	top = i - 1;
	i = 0;
	while (av[i])
	{
		if (validator(ms, av[top - i], i))
			ms->a->stack[i] = ft_atoi(av[top - i]);
		else
		{
			free_ms(ms);
			ft_printf("Error\n");
			exit(1);
		}
		i++;
		ms->a->len = i;
		find_min_max(ms->a, ms->a->len);
		ms->max = ms->a->max;
		ms->min = ms->a->min;
		ms->total = i;
	}
}
