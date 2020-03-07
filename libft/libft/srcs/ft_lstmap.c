/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:50:43 by lelida            #+#    #+#             */
/*   Updated: 2019/09/17 19:02:45 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_del(void *content, size_t content_size)
{
	while (content_size)
	{
		ft_memdel(&content[content_size]);
		content_size--;
	}
	free(content);
	content = NULL;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*obj;

	if (lst && f)
	{
		if (!(obj = (t_list*)malloc(sizeof(t_list))))
		{
			ft_lstdel(&obj, ft_del);
			return (NULL);
		}
		obj = f(lst);
		obj->next = ft_lstmap(lst->next, f);
		return (obj);
	}
	return (NULL);
}
