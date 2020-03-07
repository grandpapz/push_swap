/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_additional_char_str.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:07:07 by lelida            #+#    #+#             */
/*   Updated: 2020/01/30 18:54:22 by lhitmonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_width_str(t_tab *tab)
{
	int len;

	len = (int)ft_strlen(tab->out);
	while (tab->flag.width-- > len)
	{
		if (tab->flag.zero == 1)
			tab->ret += write(tab->fd, "0", 1);
		if (tab->flag.zero == 0)
			tab->ret += write(tab->fd, " ", 1);
	}
}

void	printf_width_char(t_tab *tab)
{
	while (tab->flag.width-- > 1)
	{
		if (tab->flag.zero == 1)
			tab->ret += write(tab->fd, "0", 1);
		if (tab->flag.zero == 0)
			tab->ret += write(tab->fd, " ", 1);
	}
}

void	huba_buba(t_tab *tab)
{
	tab->mod.l = 1;
	tab->i++;
}
