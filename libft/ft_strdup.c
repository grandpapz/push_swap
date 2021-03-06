/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:56:03 by lelida            #+#    #+#             */
/*   Updated: 2020/07/09 14:56:05 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *s1)
{
	int		counter;
	int		len;
	char	*res;

	len = ft_strlen(s1);
	res = (char*)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	counter = 0;
	while (s1[counter])
	{
		res[counter] = s1[counter];
		counter++;
	}
	res[counter] = '\0';
	return (res);
}
