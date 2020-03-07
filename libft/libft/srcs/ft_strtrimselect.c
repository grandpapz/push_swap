/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimselect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 21:58:20 by lelida            #+#    #+#             */
/*   Updated: 2019/09/25 21:58:22 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_trailing(const char *s, char c)
{
	int		j;

	j = ft_strlen(s) - 1;
	while (s[j] == c)
		j--;
	return (j);
}

static int	ft_get_leading(const char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] == c)
		i++;
	return (i);
}

char		*ft_strtrimselect(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*str;

	i = ft_get_leading(s, c);
	j = ft_get_trailing(s, c);
	k = 0;
	if (i > j)
	{
		if (!(str = ft_strnew(1)))
			return (NULL);
	}
	else
	{
		if (!(str = ft_strnew((j + 1) - i)))
			return (NULL);
		while (i <= j)
		{
			str[k] = s[i];
			i++;
			k++;
		}
	}
	return (str);
}
