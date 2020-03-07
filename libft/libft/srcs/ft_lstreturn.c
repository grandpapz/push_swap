/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreturn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 21:31:19 by lelida            #+#    #+#             */
/*   Updated: 2019/09/25 21:31:21 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstreturn(t_list *lst, size_t n)
{
	size_t	i;
	t_list	*tmp;
	t_list	*ptr;

	if (!lst)
		return (NULL);
	i = 0;
	ptr = lst;
	while (i < n && tmp)
	{
		tmp = ptr->next;
		ptr = tmp;
		i++;
	}
	return (ptr);
}
