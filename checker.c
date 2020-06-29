/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 14:39:30 by lelida            #+#    #+#             */
/*   Updated: 2020/06/29 16:29:47 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void		do_swap(t_ms *ms, char c)
{
	int tmp;

	if (c == 'a')
	{
		tmp = ms->a->stack[ms->a->len - 1];
		ms->a->stack[ms->a->len - 1] = ms->a->stack[ms->a->len - 2];
		ms->a->stack[ms->a->len - 2] = tmp;
	}
	if (c == 'b')
	{
		tmp = ms->b->stack[ms->b->len - 1];
		ms->b->stack[ms->b->len - 1] = ms->b->stack[ms->b->len - 2];
		ms->b->stack[ms->b->len - 2] = tmp;
	}
}

static void		do_rot(t_ms *ms, char *op)
{
	if (ft_strequ(op, "ra"))
		rotate(ms->a, 'c');
	else if (ft_strequ(op, "rb"))
		rotate(ms->b, 'c');
	else if (ft_strequ(op, "rr"))
	{
		rotate(ms->a, 'c');
		rotate(ms->b, 'c');
	}
	if (ft_strequ(op, "rra"))
		revrot(ms->a, 'c');
	else if (ft_strequ(op, "rrb"))
		revrot(ms->b, 'c');
	else if (ft_strequ(op, "rrr"))
	{
		revrot(ms->a, 'c');
		revrot(ms->b, 'c');
	}
}

static int		do_op(t_ms *ms, char *op)
{
	if (ft_strequ(op, "sa"))
		do_swap(ms, 'a');
	else if (ft_strequ(op, "sb"))
		do_swap(ms, 'b');
	else if (ft_strequ(op, "ss"))
	{
		do_swap(ms, 'a');
		do_swap(ms, 'b');
	}
	else if (ft_strequ(op, "pa"))
		push(ms->b, ms->a, 'c');
	else if (ft_strequ(op, "pb"))
		push(ms->a, ms->b, 'c');
	else if (ft_strequ(op, "ra") || ft_strequ(op, "rb") ||
			ft_strequ(op, "rr") || ft_strequ(op, "rra") ||
			ft_strequ(op, "rrb") || ft_strequ(op, "rrr"))
	{
		do_rot(ms, op);
		return (0);
	}
	else
		return (-1);
	return (0);
}

static void		read_op(t_ms *ms)
{
	char *op;

	while (get_next_line(0, &op) > 0)
	{
		if (!op || ft_strcmp(op, "\n") == 0)
			break ;
		if (do_op(ms, op))
		{
			ft_printf("Error\n");
			free_ms(ms);
			free(op);
			exit(1);
		}
		free(op);
		op = NULL;
	}
	op = NULL;
	free(op);
}

int				main(int ac, char *av[])
{
	t_ms	*ms;
	char	**str;

	str = NULL;
	if (ac < 2)
		exit(0);
	av++;
	ac--;
	ms = (t_ms *)malloc(sizeof(t_ms));
	if (ac >= 1)
		str = arg_splt(ac, av);
	if (ac == 1)
		init_stacks(ms, count_str(str));
	else
		init_stacks(ms, ac);
	create_stack(str, ms);
	free_str(str);
	read_op(ms);
	if (is_sorted(ms->a, ms->total) && ms->b->len == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_ms(ms);
	return (0);
}
