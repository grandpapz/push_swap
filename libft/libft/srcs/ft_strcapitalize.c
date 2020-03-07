/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 21:47:00 by lelida            #+#    #+#             */
/*   Updated: 2019/09/25 21:47:02 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = -1;
	s = str;
	ft_strlowcase(str);
	while (s[i] != '\0')
	{
		if (j == -1 || ft_isalnum(s[j]) == 0)
		{
			if (s[i] >= 'a' && s[i] <= 'z')
				s[i] -= 32;
		}
		i++;
		j++;
	}
	return (str);
}
