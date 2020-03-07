/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:20:14 by lelida            #+#    #+#             */
/*   Updated: 2019/09/09 10:46:49 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	if (src == NULL && dst == NULL)
		return (dst);
	while (++i < n)
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	return (dst);
}
