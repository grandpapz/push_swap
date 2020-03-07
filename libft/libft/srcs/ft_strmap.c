/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 21:50:12 by lelida            #+#    #+#             */
/*   Updated: 2019/09/25 21:50:17 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char *s, char (*f)(char))
{
	char			*str;
	unsigned int	i;

	if (!(s || f))
		return (NULL);
	if (!(str = ft_strnew(ft_strlen(s))))
		return (0);
	if (s && f)
	{
		i = 0;
		while (s[i])
		{
			str[i] = f(s[i]);
			i++;
		}
	}
	return (str);
}
