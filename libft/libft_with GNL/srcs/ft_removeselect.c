/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_removeselect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 21:45:52 by lelida            #+#    #+#             */
/*   Updated: 2019/09/25 21:45:54 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_removeselect(const char *s, char c)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = ft_strnew(ft_strlen(s));
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i] == s[i - 1])
			i++;
		if (!(s[i] == c && s[i] == s[i - 1]))
		{
			str[j] = s[i];
			i++;
			j++;
		}
	}
	str[j] = '\0';
	return (str);
}
