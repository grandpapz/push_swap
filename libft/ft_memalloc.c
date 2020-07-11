/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:51:41 by lelida            #+#    #+#             */
/*   Updated: 2020/07/09 14:51:42 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *ptr;

	ptr = NULL;
	if (!(ptr = (unsigned char *)malloc(size)))
		return (NULL);
	while (size--)
	{
		ptr[size] = 0;
	}
	return ((void *)ptr);
}
