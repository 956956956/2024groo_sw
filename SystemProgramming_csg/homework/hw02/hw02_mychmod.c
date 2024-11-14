//2023016057 Jo Singeun

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>

mode_t av_to_mode(char* av){
	mode_t mode = 0;
	int permission = strtol(av, NULL, 8);

	if(permission & S_IRUSR) mode += 0400;
	if(permission & S_IWUSR) mode += 0200;
	if(permission & S_IXUSR) mode += 0100;

	if(permission & S_IRGRP) mode += 0040;
	if(permission & S_IWGRP) mode += 0020;
	if(permission & S_IXGRP) mode += 0010;

	if(permission & S_IROTH) mode += 0004;
	if(permission & S_IWOTH) mode += 0002;
	if(permission & S_IXOTH) mode += 0001;

	return mode;
}

void reset(char *filename, mode_t st_mode){
	mode_t reset_mode = st_mode & ~(S_IRWXU | S_IRWXG | S_IRWXO);
	chmod(filename, reset_mode);
	printf("2.reset mode: %o -> ", reset_mode);
}

void change(char *filename, mode_t st_mode, char* av){
	mode_t change_mode = 0100000 | av_to_mode(av);
	chmod(filename, change_mode);
	printf("changed mode = %o\n", change_mode);
}

int main(int ac, char* av[]){
	if(ac != 3){
		printf("Usage: mychmod [permission] [filename]\n");
		exit(1);
	}

	struct stat buf;
	if(stat(av[2], &buf) == -1){
		perror("Error");
		exit(1);
	}
	printf("1.current mode: %o -> ", buf.st_mode);

	reset(av[2], buf.st_mode);

	change(av[2], buf.st_mode, av[1]);

	return 0;
}

