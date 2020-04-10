/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <lelida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 19:28:16 by lelida            #+#    #+#             */
/*   Updated: 2019/09/25 20:42:02 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			line_cp(char **line, char *content, char c)
{
	int		i;
	char	*temp;

	i = 0;
	temp = *line;
	while (content[i] && content[i] != c)
		i++;
	if (!(*line = ft_strndup(content, i)))
		return (0);
	return (i);
}

t_list		*get_str(int fd, t_list **nlist)
{
	t_list *temp;

	if (!nlist)
		return (NULL);
	temp = *nlist;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	temp = ft_lstnew("", fd);
	ft_lstadd(nlist, temp);
	return (temp);
}

int			reader(const int fd, char **content)
{
	int		result;
	char	*temp;
	char	buff[BUFF_SIZE + 1];

	while ((result = read(fd, buff, BUFF_SIZE)))
	{
		buff[result] = '\0';
		temp = *content;
		if (!(*content = ft_strjoin(*content, buff)))
			return (-1);
		free(temp);
		if (ft_strchr(buff, ENDL))
			break ;
	}
	return (result);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*nlist;
	char			buff[BUFF_SIZE + 1];
	char			*temp;
	size_t			result;
	t_list			*llist;

	if (fd < 0 || !line || (read(fd, buff, 0)) < 0 ||
			(!(llist = get_str(fd, &nlist))))
		return (-1);
	temp = llist->content;
	result = reader(fd, &temp);
	llist->content = temp;
	if (!result && !*temp)
		return (0);
	result = line_cp(line, llist->content, ENDL);
	temp = llist->content;
	if (temp[result] != '\0')
	{
		llist->content = ft_strdup(&((llist->content[result + 1])));
		free(temp);
	}
	else
		temp[0] = '\0';
	return (1);
}
