//2023016057 Jo Singeun

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void maketree(){
	DIR *dir_ptr = NULL;
	struct dirent *dirent_ptr = NULL;
	char path[30][256];
	int cnt = -1;

	if((dir_ptr = opendir(".")) == NULL){
		perror(NULL);
		exit(-1);
	}

	while((dirent_ptr = readdir(dir_ptr)) != NULL){
		if(S_ISDIR(dirent_ptr->d_ino)){
			strncpy(path[++cnt], dirent_ptr->d_name, 256);
			printf("%s\n", dirent_ptr->d_name);
		}
	}
	closedir(dir_ptr);
}

int main(int ac, char* av[]){
	if(ac == 1){
		printf("Usage: ./dir_tree [filename]\n");
		return 0;
	}

	DIR *dir_ptr = NULL;
	struct dirent *dirent_ptr = NULL;

	if((dir_ptr = opendir(av[1])) == NULL){
		printf("%s cannnot open!\n", av[1]);
		exit(-1);
	}
	
	maketree();

	closedir(dir_ptr);
	return 0;
}