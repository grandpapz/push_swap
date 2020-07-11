/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:53:11 by lelida            #+#    #+#             */
/*   Updated: 2020/07/09 14:53:12 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

long double	ft_power(long double nbr, int n)
{
	if (n == 0)
		return (1);
	if (n < 0)
		return (ft_power(1.0 / nbr, -n));
	return (nbr * ft_power(nbr, n - 1));
}
