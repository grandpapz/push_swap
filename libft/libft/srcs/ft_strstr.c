/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:36:31 by lelida            #+#    #+#             */
/*   Updated: 2019/09/05 12:48:52 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *a;
	char *b;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		a = (char *)haystack;
		b = (char *)needle;
		while (*b && *a == *b)
		{
			a++;
			b++;
		}
		if (*b == '\0')
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
