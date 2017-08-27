#include "gnl.c"
#include "libft/libft.h"
#include <stdio.h>

int main(){
	int fd, fd2, fd3, fd4, fd5, fd6;
	int disp = 0;
	int	do_tests = 0;
	int i;
	int j;
	int k;
	char *line = malloc(128);
	char *filename;
	char *filename2;
	char *first_line;
	char *second_line;
	char *file1;
	char *file2;


	disp = 1;
	do_tests = 1;
	if (do_tests){
		if (disp) printf("asserting error cases ...\n");
		assert(get_next_line(-32, &line) == -1);
		assert(get_next_line(1, NULL) == -1);
		assert(get_next_line(5, &line) == -1);
	}

	if (do_tests){
		if (disp) printf("asserting case line length < buff_size ...\n");
		filename = strdup("one_short_line.txt");
		fd = open(filename, O_RDONLY);
		assert(get_next_line(fd, &line));
		if (disp) printf("\tasserting [%s] with [%s] ...\n", line, filename);
		assert(!strcmp(line, filename));
		assert(!get_next_line(fd, &line));
	}

	if (do_tests){
		if (disp) printf("asserting case line length > buff_size ...\n");
		filename = strdup("one_long_line.txt");
		first_line = strdup("Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
		fd2 = open(filename, O_RDONLY);
		// printf("first gnl\n");
		assert(get_next_line(fd2, &line));
		if (disp) printf("\tasserting [%s] with [%s] ...\n", line, first_line);
		assert(!strcmp(line, first_line));
		// printf("second gnl\n");
		assert(!get_next_line(fd2, &line));
	}

	if (do_tests){
		if (disp) printf("asserting case with several long lines ...\n");
		filename = strdup("two_long_lines.txt");
		first_line = strdup("Lorem ipsum dolor sit amet, consectetur adipiscing elit. ");
		second_line = strdup("Maecenas congue felis ut nunc commodo, eu feugiat sem malesuada. ");
		fd3 = open(filename, O_RDONLY);
		assert(get_next_line(fd3, &line));
		if (disp) printf("\tasserting \n[%s] with \n[%s] ...\n", line, first_line);
		assert(!strcmp(line, first_line));
		assert(get_next_line(fd3, &line));
		if (disp) printf("\tasserting \n[%s] with \n[%s] ...\n", line, second_line);
		assert(!strcmp(line, second_line));
	}

	if (do_tests){
		if (disp) printf("asserting case with a full file ...\n");
		filename = strdup("get_next_line.h");
		fd4 = open(filename, O_RDONLY);
		while (get_next_line(fd4, &line) == 1){
			printf("%s\n", line);
			ft_strclr(line);
		}
		// should be the same as get_next_line.h
	}

	do_tests = 1;
	if (do_tests){
		printf("before:[%s]\n", line);
		if (disp) printf("asserting case with multiple full files ...\n");
		filename = strdup("dup.c");
		fd5 = open(filename, O_RDONLY);
		filename2 = strdup("get_next_line.h");
		fd6 = open(filename2, O_RDONLY);
		i = 1;
		// int l = 0;
		file1 = ft_strnew(1);
		file2 = ft_strnew(1);
		while (i){
			j = get_next_line(fd5, &line);
			printf("file1:[%s]\n", line);
			if (j == 1){
				file1 = ft_strjoin(file1, line);
				file1 = ft_strjoin(file1, "\n");
				// if (!l){
				// 	printf("full file1:[%s]\n", file1);
				// }
			}
			k = get_next_line(fd6, &line);
			printf("file2:[%s]\n", line);
			if (k == 1)
			{
				file2 = ft_strjoin(file2, line);
				file2 = ft_strjoin(file2, "\n");
				// if (!l){
				// 	printf("full file2:[%s]\n", file2);
				// }
			}
			if (!j && !k)
				i = 0;
			// ++l;
		}
		printf("[%s]\n", file1);
		printf("[%s]\n", file2);
		close(fd);
		close(fd2);
		close(fd3);
		close(fd4);
		close(fd5);
		close(fd6);
	}
	printf("test ok\n");
}
