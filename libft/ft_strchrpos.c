/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrpos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:55:06 by lelida            #+#    #+#             */
/*   Updated: 2020/07/09 14:55:08 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strchrpos(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	else
		return (0);
}
