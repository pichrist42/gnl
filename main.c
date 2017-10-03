#include "libft/libft.h"
#include <fcntl.h>

int				get_next_line(const int fd, char **line);

int main(){
	int fd = open("main.c", O_RDONLY);
	char *line;
	if (get_next_line(fd, &line))
		ft_putendl(line);
	else
		ft_putendl("no line");
}
