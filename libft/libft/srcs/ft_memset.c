/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:16:14 by lelida            #+#    #+#             */
/*   Updated: 2019/09/06 13:18:15 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*cur;

	if (len == 0)
		return (b);
	cur = (unsigned char*)b;
	while (len--)
	{
		*cur = (unsigned char)c;
		if (len)
			cur++;
	}
	return (b);
}
