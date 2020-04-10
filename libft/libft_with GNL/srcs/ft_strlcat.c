/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 21:49:32 by lelida            #+#    #+#             */
/*   Updated: 2019/09/25 21:49:33 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = (ft_strlen(dst) < dstsize) ? ft_strlen(dst) : dstsize;
	len += ft_strlen(src);
	if (dstsize)
	{
		while (*dst)
		{
			dst++;
			i++;
		}
		while (*src && i < (dstsize - 1))
		{
			*dst++ = *src++;
			i++;
		}
		*dst = '\0';
	}
	return (len);
}
