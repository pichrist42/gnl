#include "gnl.c"

int main(){
	int fd;
	int disp = 0;
	char *line = malloc(128);
	char *filename;
	char *first_line;
	char *second_line;

	if (disp) printf("asserting error cases ...\n");
	assert(get_next_line(-32, &line, 0) == -1);
	assert(get_next_line(1, NULL, 0) == -1);
	assert(get_next_line(5, &line, 0) == -1);

	if (disp) printf("asserting case line length < buff_size ...\n");
	filename = strdup("one_short_line.txt");
	fd = open(filename, O_RDONLY);
	assert(get_next_line(fd, &line, 0));
	if (disp) printf("\tasserting [%s] with [%s] ...\n", line, filename);
	assert(!strcmp(line, filename));
	assert(!get_next_line(fd, &line, 0));
	close(fd);

	if (disp) printf("asserting case line length > buff_size ...\n");
	filename = strdup("one_long_line.txt");
	first_line = strdup("Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
	fd = open(filename, O_RDONLY);
	assert(get_next_line(fd, &line, 0));
	if (disp) printf("\tasserting [%s] with [%s] ...\n", line, first_line);
	assert(!strcmp(line, first_line));
	assert(!get_next_line(fd, &line, 0));
	close(fd);

	if (disp) printf("asserting case with several long lines ...\n");
	filename = strdup("two_long_lines.txt");
	first_line = strdup("Lorem ipsum dolor sit amet, consectetur adipiscing elit. ");
	second_line = strdup("Maecenas congue felis ut nunc commodo, eu feugiat sem malesuada. ");
	fd = open(filename, O_RDONLY);
	assert(get_next_line(fd, &line, 0));
	if (disp) printf("\tasserting \n[%s] with \n[%s] ...\n", line, first_line);
	assert(!strcmp(line, first_line));
	assert(get_next_line(fd, &line, 1));
	disp = 1;
	// erreur ici
	if (disp) printf("\tasserting \n[%s] with \n[%s] ...\n", line, second_line);
	assert(strcmp(line, second_line));
	close(fd);

	/*	pas testé
		if (disp) printf("asserting case with a full file ...\n");
		filename = strdup("get_next_line.h");
		fd = open(filename, O_RDONLY);
		while (get_next_line(fd, &line, 0))
			printf("%s\n", line);
		// should be the same as get_next_line.h
		close(fd);

		if (disp) printf("asserting case with multiple full files ...\n");
		// not implemented yet
	*/
	
	printf("test ok\n");
}
