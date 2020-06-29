/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 16:35:47 by lelida            #+#    #+#             */
/*   Updated: 2020/06/29 19:55:03 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	free_str(char *str[])
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
	str = NULL;
}

void	ft_usage(void)
{
	ft_printf("Usage: ./push_swap [integer array]\n");
	exit(0);
}

int		count_str(char *str[])
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
