/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:18:59 by lelida            #+#    #+#             */
/*   Updated: 2019/09/12 19:36:51 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*p_dst;
	const unsigned char	*p_src;

	p_dst = (unsigned char*)dst;
	p_src = (unsigned char*)src;
	i = 0;
	if (dst == src)
		return (dst);
	if (p_src < p_dst)
		while (++i <= len)
			p_dst[len - i] = p_src[len - i];
	else
		while (len-- > 0)
			*(p_dst++) = *(p_src++);
	return (dst);
}
