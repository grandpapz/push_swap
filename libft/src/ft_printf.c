/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 18:15:33 by lelida            #+#    #+#             */
/*   Updated: 2020/01/30 18:16:07 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_tab	tab;

	ft_bzero(&tab, sizeof(tab));
	tab.fd = 1;
	tab.format = (char*)format;
	va_start(tab.list, format);
	while (format[tab.i] != '\0')
	{
		if (format[tab.i] == '%' && format[tab.i + 1] == '\0')
			tab.i++;
		else if (format[tab.i] == '%' && format[tab.i + 1] != '%')
			parse_format(&tab);
		else if (format[tab.i] == '%' && format[tab.i + 1] == '%')
		{
			tab.ret += write(tab.fd, "%", 1);
			tab.i += 2;
		}
		else
			tab.ret += write(tab.fd, &format[tab.i++], 1);
	}
	va_end(tab.list);
	return (tab.ret);
}
