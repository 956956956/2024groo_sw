#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(){
	int fd;
	fd = open("anyfile", O_RDONLY);
	if(fd == -1){
		perror("open ");
		exit(-1);
	}
	return 0;
}