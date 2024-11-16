// 2023012565 kimeunjeong
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char fullpath[30][256] = {0,};

ino_t get_inode(char *);
void print_path_to(ino_t);
void inode_to_name(ino_t, char *, int);

int main() {
	print_path_to(get_inode("."));
	putchar('\n');
	return 0;
}

void print_path_to(ino_t inode) {
	int i = 0;

	while (get_inode("..") != inode) {
		char its_name[256];
		chdir("..");
		inode_to_name(inode, its_name, 256);
		inode = get_inode(".");
		strncpy(fullpath[i++], its_name, strlen(its_name));
	}

	for (int j = 0; j < i; j++)
		printf("[%s] -> ", fullpath[j]);

	printf("/\n\n");
	printf("--------------------------\n");
	printf("Print working directory\n");
	printf("--------------------------\n");

	while(i > 0)
		printf("/%s", fullpath[--i]);
}

void inode_to_name(ino_t inode_to_find, char *namebuf, int buflen) {
	DIR *dir_ptr = NULL;
	struct dirent *dirent_ptr = NULL;

	if ((dir_ptr = opendir(".")) == NULL) {
		perror(NULL);
		exit(-1);
	}

	while ((dirent_ptr = readdir(dir_ptr)) != NULL) {
		if (dirent_ptr->d_ino == inode_to_find) {
			strncpy(namebuf, dirent_ptr->d_name, buflen);
			closedir(dir_ptr);
			namebuf[buflen-1] = '\0';
			return;
		}
	}
	fprintf(stderr, "error looking for inode: %ld\n", inode_to_find);
	exit(1);
}

ino_t get_inode(char *filename) {
	struct stat info;
	if (stat(filename, &info) == -1) {
		fprintf(stderr, "cannot stat ");
		perror(NULL);
		exit(-1);
	}
	return info.st_ino;
}