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

char	**arg_splt(int ac, char *av[])
{
	char	**str;
	int		i;

	i = -1;
	if (ac == 1)
		str = ft_strsplit(av[0], ' ');
	else
	{
		if (!(str = (char **)malloc(sizeof(char *) * ac + 1)))
			exit(1);
		while (av[++i])
			str[i] = ft_strdup(av[i]);
		str[i] = NULL;
	}
	return (str);
}
