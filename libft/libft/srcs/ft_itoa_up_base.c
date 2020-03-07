/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_up_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 19:45:02 by lelida            #+#    #+#             */
/*   Updated: 2020/01/30 19:45:24 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_up_base(unsigned long n, int base)
{
	char			*s;
	unsigned long	nb;
	int				len;

	len = 1;
	nb = n;
	while (nb >= (unsigned)base)
	{
		nb /= base;
		++len;
	}
	s = (char*)malloc(sizeof(char) * (len + 1));
	s[len] = '\0';
	while (n >= (unsigned)base)
	{
		s[--len] = n % base < 10 ? (n % base) + 48 : (n % base) + 55;
		n /= base;
	}
	s[--len] = n % base < 10 ? (n % base) + 48 : (n % base) + 55;
	return (s);
}
