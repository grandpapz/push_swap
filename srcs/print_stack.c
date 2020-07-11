/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 13:30:40 by lelida            #+#    #+#             */
/*   Updated: 2020/07/09 13:30:44 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		print_stack(t_node *src, t_node *dst, char *opt, t_stack *st)
{
	ft_printf("\033[39;1mOperation : \033[33;1m%s\033[m\n", opt ? opt : "");
	ft_printf("\033[39;1mCounter   : %d\n", st->count++);
	ft_printf("  Stack A   Stack B\033[0m\n");
	while (src || dst)
	{
		if ((src && src->prev && src->data > src->prev->data) || (src && \
			!src->prev))
			src ? ft_printf("\033[32;1m%9d\033[0m |", src->data) : \
				ft_printf("          |");
		else
			src ? ft_printf("\033[31;1m%9d\033[0m |", src->data) : \
				ft_printf("          |");
		if ((dst && dst->prev && dst->data < dst->prev->data) || (dst && \
			!dst->prev))
			dst ? ft_printf("\033[32;1m%2d\033[0m\n", dst->data) : \
				ft_printf("  \n");
		else
			dst ? ft_printf("\033[31;1m%2d\033[0m\n", dst->data) : \
				ft_printf("  \n");
		src ? (src = src->next) : 0;
		dst ? (dst = dst->next) : 0;
	}
}
