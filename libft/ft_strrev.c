/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:58:49 by lelida            #+#    #+#             */
/*   Updated: 2020/07/09 14:58:50 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrev(char *src)
{
	char	*dst;
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (src[k])
		k++;
	if (!(dst = (char *)malloc(sizeof(char) * k + 1)))
		return (NULL);
	while (--k >= 0)
		dst[i++] = src[k];
	dst[i] = '\0';
	return (dst);
}
