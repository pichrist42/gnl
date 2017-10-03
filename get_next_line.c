/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 15:45:49 by pichrist          #+#    #+#             */
/*   Updated: 2017/10/03 11:23:52 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static t_mem	*first = NULL;
	t_mem			*item;
	char			buffer[BUFF_SIZE + 1];
	int				c;

	if (!BUFF_SIZE)
		return (0);
	if (fd < 0 || !line ||
		(first == NULL && !(first = alloc_item(fd, ft_strnew(1)))))
		return (-1);
	item = check_item_fd(first, fd);
	while ((c = read(fd, buffer, BUFF_SIZE)))
	{
		if (c == -1)
			return (-1);
		buffer[c] = '\0';
		add_buffer(item, buffer);
	}
	return (result(item, line));
}

t_mem	*check_item_fd(t_mem *item, int fd)
{
	while (item->next && item->fd != fd)
		item = item->next;
	if (item->fd != fd)
	{
		item->next = alloc_item(fd, ft_strnew(1));
		item = item->next;
	}
	return (item);
}

t_mem	*alloc_item(int fd, char *str)
{
	t_mem	*item;

	if (!(item = (t_mem*)malloc(sizeof(t_mem))))
		return (NULL);
	item->data = str;
	item->fd = fd;
	item->next = NULL;
	return (item);
}

void	add_buffer(t_mem *item, char *buffer)
{
	char *tmp;

	tmp = ft_strdup(item->data);
	free(item->data);
	item->data = ft_strjoin(tmp, buffer);
	free(tmp);
	tmp = NULL;
}

int		result(t_mem *item, char **line)
{
	char *tmp;

	if (!item->data || !item->data[0])
		return (0);
	else if ((tmp = ft_strchr(item->data, '\n')))
	{
		*line = ft_strdupu(item->data, "\n");
		ft_memmove(item->data, tmp + 1, ft_strlen(tmp));
	}
	else
	{
		*line = item->data;
		item->data = NULL;
		ft_strclr(item->data);
	}
	return (1);
}
