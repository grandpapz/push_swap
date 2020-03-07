/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:38:41 by lelida            #+#    #+#             */
/*   Updated: 2019/09/09 14:36:19 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a “fresh” memory area.
** The memory allocated is initialized to 0. If the allocation fails,
** the function returns NULL
*/

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *p;

	p = malloc(size);
	if (!p)
		return (NULL);
	ft_bzero(p, size);
	return (p);
}
