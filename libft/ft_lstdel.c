/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:50:47 by lelida            #+#    #+#             */
/*   Updated: 2020/07/09 14:50:48 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *acnt;
	t_list *anxt;

	acnt = *alst;
	while (acnt)
	{
		anxt = acnt->next;
		del((acnt->content), (acnt->content_size));
		free(acnt);
		acnt = anxt;
	}
	*alst = NULL;
}
