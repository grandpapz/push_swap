/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 10:42:06 by lelida            #+#    #+#             */
/*   Updated: 2019/09/09 11:01:04 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long int	i;
	unsigned long long int	num;
	int						sign;

	i = 0;
	num = 0;
	sign = 1;
	while (*(str + i) == '\n' ||
			*(str + i) == '\t' ||
			*(str + i) == '\r' ||
			*(str + i) == '\v' ||
			*(str + i) == '\f' ||
			*(str + i) == ' ')
		i++;
	if (*(str + i) == '-')
		sign = -1;
	if (*(str + i) == '-' || *(str + i) == '+')
		i++;
	while (*(str + i) && *(str + i) >= '0' && *(str + i) <= '9')
		num = num * 10 + (*(str + i++) - '0');
	if (num > 9223372036854775807 && sign == 1)
		return (-1);
	else if (num > 9223372036854775807 && sign == -1)
		return (0);
	return (num * sign);
}
