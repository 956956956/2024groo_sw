#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main(){
	char buf[] = "Hello World!\n";
	int fd = 0;
	fd = open("data.txt", O_CREAT|O_WRONLY|O_TRUNC, 0644);
	if(fd == -1)
		printf("open() error!\n");

	printf("file descriptor: %d \n", fd);
	int len = write(fd, buf, sizeof(buf));
	if(len == -1)
		printf("write() error!\n");
	else
		printf("write length %d\n", len);
	close(fd);
	return 0;
}