/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:15:54 by lelida            #+#    #+#             */
/*   Updated: 2019/09/12 20:24:49 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;
	t_list	*tmp;

	if (*alst && alst && del)
	{
		ptr = *alst;
		while (ptr)
		{
			tmp = ptr;
			ft_lstdelone(&ptr, del);
			ptr = tmp->next;
		}
		*alst = NULL;
	}
}
