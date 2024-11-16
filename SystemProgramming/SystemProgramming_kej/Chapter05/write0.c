#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(int ac, char *av[]) {
	int fd = 0;
	char buf[BUFSIZ];

	if (ac!=2) {
		fprintf(stderr, "Usage: write0 ttyname\n");
		exit(-1);
	}

	fd = open(av[1], O_WRONLY);
	if (fd == -1) {
		perror(av[1]);
		exit(-1);
	}

	while(fgets(buf, BUFSIZ, stdin) != NULL) {
		printf("one iteration executed\n");
		if (write(fd, buf, strlen(buf)) == -1) {
			break;
		}
		printf("write one piece of contents\n");
	}
	close(fd);
}