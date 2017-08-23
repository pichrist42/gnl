/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 20:35:13 by pichrist          #+#    #+#             */
/*   Updated: 2017/08/21 16:37:34 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <assert.h>

typedef struct		s_mem
{
	char			*data;
	int				fd;
	struct s_mem	*next;
}					t_mem;

int			get_next_line(const int fd, char **line, int disperr);
static void	add_buffer(char **content, char *buffer);
static int	result(char **content, char **line, int disp_err);

#endif
