/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 19:35:35 by lelida            #+#    #+#             */
/*   Updated: 2020/01/30 19:36:11 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(unsigned long n, int base)
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
		s[--len] = n % base < 10 ? (n % base) + 48 : (n % base) + 87;
		n /= base;
	}
	s[--len] = n % base < 10 ? (n % base) + 48 : (n % base) + 87;
	return (s);
}
