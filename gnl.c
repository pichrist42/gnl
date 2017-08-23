/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 15:45:49 by pichrist          #+#    #+#             */
/*   Updated: 2017/08/21 17:49:46 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	debug(char *msg, int disp_err){
	if (disp_err)
		ft_putendl(msg);
}

int			get_next_line(const int fd, char **line, int disp_err)
{
	static char	*content = NULL;
	char		buffer[BUFF_SIZE + 1];
	int			c;

	if (fd < 0 || !line)
		return (-1);
	if (!BUFF_SIZE)
		return (0);
	while (c = read(fd, buffer, BUFF_SIZE))
	{
		if (c == -1)
			return (-1);
		buffer[c] = '\0';
		if (content)
			add_buffer(&content, buffer);
		else
			content = ft_strdup(buffer);
	}
	return (result(&content, line, disp_err));
}

static void	add_buffer(char **content, char *buffer)
{
	char *tmp;

	tmp = ft_strdup(*content);
	ft_memdel((void**)content);
	*content = ft_strjoin(tmp, buffer);
	free(tmp);
	tmp = NULL;
	// ft_strclr(buffer);
}

static int	result(char **content, char **line, int disp_err)
{
	char *tmp;

	if (!*content || !*content[0])
		return (0);
	else if ((tmp = ft_strchr(*content, '\n')))
	{
		*line = ft_strdupu(*content, "\n");
		ft_memmove(*content, tmp + 1, ft_strlen(tmp));
	}
	else
	{
		*line = *content;
		// *content = NULL;
		ft_strclr(*content);
		ft_putendl(*line);
	}
	return (1);
}
