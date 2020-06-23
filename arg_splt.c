/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_splt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 14:37:52 by lelida            #+#    #+#             */
/*   Updated: 2020/06/23 14:38:14 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int		is_sign(char c)
{
	return (c == '-' || c == '+');
}

char	**arg_splt(int *ac, char ***av)
{
	char **str;

	str = ft_strsplit((*av)[0], ' ');
	(*ac) = 0;
	while (str && str[*ac])
		(*ac)++;
	if (*ac == 0)
	{
		ft_printf("Error\n");
		exit(1);
	}
	return (str);
}
