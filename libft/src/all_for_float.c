/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_for_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhitmonc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:53:09 by lhitmonc          #+#    #+#             */
/*   Updated: 2020/01/30 18:31:01 by lhitmonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_float(t_tab *tab)
{
	long double			output;
	double				long_output;

	if (tab->mod.kek)
	{
		output = va_arg(tab->list, long double);
	}
	else
	{
		long_output = va_arg(tab->list, double);
		output = (long double)long_output;
	}
	printf_float(tab, output);
}

void	hochu_pitsu(t_tab *tab)
{
	if (tab->flag.plus == 1)
		tab->ret += write(tab->fd, "+", 1);
	else
		write(tab->fd, " ", 1);
}

void	printf_float(t_tab *tab, long double output)
{
	reload_float(tab, output);
	if (tab->flag.minus)
	{
		if (output > 0 && (tab->flag.plus || tab->flag.space))
			hochu_pitsu(tab);
		tab->ret += write(tab->fd, tab->out, ft_strlen(tab->out));
		print_prec_width(tab);
	}
	else
	{
		if (ft_atoi(tab->out) > 0 && (tab->flag.plus || tab->flag.space))
		{
			if (tab->flag.plus == 1)
				tab->ret += write(tab->fd, "+", 1);
			else
				tab->ret += write(tab->fd, " ", 1);
		}
		print_prec_width(tab);
		tab->ret += write(tab->fd, tab->out, ft_strlen(tab->out));
	}
	++tab->i;
	free(tab->out);
}

void	print_prec_width(t_tab *tab)
{
	int i;
	int len;

	i = -1;
	len = ft_strlen(tab->out) + tab->flag.plus + tab->flag.space;
	if (tab->flag.precision >= 0)
	{
		while (tab->flag.width - ++i > len)
			if (tab->flag.zero)
				tab->ret += write(tab->fd, "0", 1);
			else
				tab->ret += write(tab->fd, " ", 1);
		i = 0;
		while ((int)ft_strlen(tab->out) < len - ++i)
			tab->ret += write(tab->fd, "0", 1);
	}
	else
		while (tab->flag.width - ++i > len)
			if (tab->flag.zero == 1)
				tab->ret += write(tab->fd, "0", 1);
			else
				tab->ret += write(tab->fd, " ", 1);
}
