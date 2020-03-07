/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:57:36 by lelida            #+#    #+#             */
/*   Updated: 2019/09/12 19:39:16 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Takes as a parameter the address of a memory area that needs
** to be freed with free(3), then puts the pointer to NULL.
*/

#include "libft.h"

void	ft_memdel(void **ap)
{
	if (ap && *ap)
	{
		free(*ap);
		*ap = NULL;
	}
}
