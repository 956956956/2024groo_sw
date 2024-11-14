//2023016057 Jo Singeun

#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <ctype.h>
#include <string.h>

int main(int ac, char* av[]){
	if(ac == 1){
		printf("Usage: ./mid0_cat [filename]\n");
		return 0;
	}

	int fd;
	char ch;
	size_t rec_len = sizeof(ch);
	int line_num = 0;

	if((fd = open(av[1], O_RDONLY)) == -1){
		printf("%s cannnot open!\n", av[1]);
		exit(-1);
	}

	printf("%3d  ", ++line_num);
	while(read(fd, &ch, rec_len) > 0){
		printf("%c", ch);
		if(ch == '\n')
			printf("%3d  ", ++line_num);
	}

	close(fd);

	return 0;		
}