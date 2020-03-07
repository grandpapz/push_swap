/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:20:17 by lelida            #+#    #+#             */
/*   Updated: 2020/01/30 17:21:21 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_int(t_tab *tab)
{
	ft_check_sign(tab);
	reload_output_with_precision(tab);
	if (tab->flag.zero == 1)
	{
		printf_sign(tab);
		printf_width(tab);
		tab->ret += write(tab->fd, tab->out, ft_strlen(tab->out));
	}
	else if (tab->flag.minus == 1)
	{
		printf_sign(tab);
		tab->ret += write(tab->fd, tab->out, ft_strlen(tab->out));
		printf_width(tab);
	}
	else
	{
		printf_width(tab);
		printf_sign(tab);
		tab->ret += write(tab->fd, tab->out, ft_strlen(tab->out));
	}
	tab->i++;
	free(tab->out);
}

void	printf_base(t_tab *tab)
{
	reload_output_with_precision(tab);
	if (tab->flag.zero == 1)
	{
		printf_hash(tab);
		printf_width(tab);
		tab->ret += write(tab->fd, tab->out, ft_strlen(tab->out));
	}
	else if (tab->flag.minus == 1)
	{
		printf_hash(tab);
		tab->ret += write(tab->fd, tab->out, ft_strlen(tab->out));
		printf_width(tab);
	}
	else
	{
		printf_width(tab);
		printf_hash(tab);
		tab->ret += write(tab->fd, tab->out, ft_strlen(tab->out));
	}
	tab->i++;
	free(tab->out);
}

void	printf_pointer(t_tab *tab)
{
	if (tab->flag.zero && tab->flag.precision == -1)
		tab->flag.precision = tab->flag.width - 2;
	reload_output_with_pointer(tab);
	if (tab->flag.minus)
	{
		tab->ret += write(tab->fd, tab->out, ft_strlen(tab->out));
		printf_pointer_width(tab);
	}
	else
	{
		printf_pointer_width(tab);
		tab->ret += write(tab->fd, tab->out, ft_strlen(tab->out));
	}
	tab->i++;
	free(tab->out);
}
