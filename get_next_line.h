/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 20:35:13 by pichrist          #+#    #+#             */
/*   Updated: 2017/10/03 11:23:47 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_mem
{
	char			*data;
	int				fd;
	struct s_mem	*next;
}					t_mem;

int					get_next_line(const int fd, char **line);
t_mem				*check_item_fd(t_mem *item, int fd);
t_mem				*alloc_item(int fd, char *str);
void				add_buffer(t_mem *item, char *buffer);
int					result(t_mem *item, char **line);

#endif
