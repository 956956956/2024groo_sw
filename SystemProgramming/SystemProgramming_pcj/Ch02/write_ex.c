#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>

int main(){
	char buf[13] = "Hello World!\n";
	int fd = 0;
	fd = open("data.txt", O_CREAT|O_WRONLY|O_TRUNC, 0644);
	if (fd == -1)
		printf("oepn() error!\n");
	
	printf("file descriptor: %d \n", fd);
	int len = write(fd, buf, sizeof(buf));
	if(len == -1)
		printf("write() error!\n");
	else
		printf("write length: %d\n", len);
	printf("%ld\n", sizeof(buf));
	close(fd);
	return 0;
}