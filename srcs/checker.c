/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 13:29:56 by lelida            #+#    #+#             */
/*   Updated: 2020/07/09 13:29:59 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	valid_operation(char *s, int (*f)(const char *, const char *))
{
	if (!f(s, "pa") || !f(s, "pb") || !f(s, "sa") || !f(s, "sb") ||
		!f(s, "ra") || !f(s, "rb") || !f(s, "rra") || !f(s, "rrb") ||
		!f(s, "ss") || !f(s, "rr") || !f(s, "rrr"))
		return (1);
	return (0);
}

static void	do_operation(t_linklist *src, t_linklist *dst, t_stack *stack, \
						char *opt)
{
	!ft_strcmp("pb", opt) ? push(src, dst, stack) : 0;
	!ft_strcmp("pa", opt) ? push(dst, src, stack) : 0;
	!ft_strcmp("sa", opt) ? swap(src, stack) : 0;
	!ft_strcmp("sb", opt) ? swap(dst, stack) : 0;
	!ft_strcmp("ss", opt) ? doub_opt(stack, opt, swap) : 0;
	!ft_strcmp("ra", opt) ? rotate(src, stack) : 0;
	!ft_strcmp("rb", opt) ? rotate(dst, stack) : 0;
	!ft_strcmp("rr", opt) ? doub_opt(stack, opt, rotate) : 0;
	!ft_strcmp("rra", opt) ? revrotate(src, stack) : 0;
	!ft_strcmp("rrb", opt) ? revrotate(dst, stack) : 0;
	!ft_strcmp("rrr", opt) ? doub_opt(stack, opt, revrotate) : 0;
}

static int	get_operations(t_linklist *src, t_linklist *dst, t_stack *stack)
{
	char	*opr;

	while (get_next_line(stack->fd, &opr) > 0)
	{
		if (!valid_operation(opr, ft_strcmp))
		{
			free(opr);
			free_stack(stack);
			print_error();
		}
		if (stack->opt & OPT_V)
			print_stack(src->head, dst->head, opr, stack);
		do_operation(src, dst, stack, opr);
		free(opr);
	}
	if (stack->opt & OPT_V)
		print_stack(src->head, dst->head, NULL, stack);
	return (1);
}

int			main(int ac, char **av)
{
	t_stack	stack;

	stack.print = 0;
	stack.count = 0;
	stack.fd = 0;
	if (ac < 2 || (ac == 2 && ft_strcmp(av[1], "-v") == 0))
		return (0);
	av += 1;
	if (init_stack(&stack, av))
		print_error();
	if (get_operations(stack.stack[A], stack.stack[B], &stack))
		ft_printf("%s\n", (issort(stack.stack[A]) && \
				!stack.stack[1]->head) ? OK : KO);
	free_stack(&stack);
	return (0);
}
