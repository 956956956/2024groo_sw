#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	struct stat statbuf;
	
	stat("test.txt", &statbuf);
	printf("test.txt: link count= %d\n", (int)statbuf.st_nlink);
	unlink("test.txt");

	// stat("linux.ln", &statbuf);
	// printf("Before unlink()linux.ln: link count= %d\n", (int)statbuf.st_nlink);
	// unlink("linux.ln");

	// stat("linux.txt", &statbuf);
	// printf("After unlink(): linux.txt: link count= %d\n", (int)statbuf.st_nlink);

	// for test
	stat("linux.txt", &statbuf);
	printf("Before unlink()linux.txt: link count= %d\n", (int)statbuf.st_nlink);
	unlink("linux.txt");

	stat("linux.txt", &statbuf);
	printf("After unlink(): linux.txt: link count= %d\n", (int)statbuf.st_nlink);

	return 0;
}