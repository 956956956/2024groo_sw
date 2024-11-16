	#include <stdio.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <dirent.h>
	#include <unistd.h>
	#include <stdlib.h>
	#include <string.h>

	ino_t get_inode(char*);
	void print_path_to(ino_t);
	void inode_to_name(ino_t, char *, int);

	int main(){
		print_path_to(get_inode("."));
		putchar('\n');
		return 0;
	}

	void print_path_to(ino_t inode){
		char fullpath[30][256];
		int cnt = 0;

		while (get_inode("..") != inode){
			chdir("..");
			inode_to_name(inode, fullpath[cnt++], 256);
			inode = get_inode(".");
            printf("[%s] -> ", fullpath[cnt - 1]);
		}
        printf("/\n\n");
        printf("------------------------\n");
        printf("Print working directory\n");
        printf("------------------------\n");

		for(int i = cnt - 1; i >= 0; i--)
			printf("/%s", fullpath[i]);
	}

	void inode_to_name(ino_t inode_to_find, char *namebuf, int buflen){
		DIR *dir_ptr = NULL;
		struct dirent *dirent_ptr = NULL;

		if((dir_ptr = opendir(".")) == NULL){
			perror(NULL);
			exit(-1);
		}

		while((dirent_ptr = readdir(dir_ptr)) != NULL){
			if(dirent_ptr->d_ino == inode_to_find){
				strncpy(namebuf, dirent_ptr->d_name, buflen);
				closedir(dir_ptr);
				namebuf[buflen - 1] = '\0';
				return;
			}
		}
		fprintf(stderr, "error looking for inode %ld\n", inode_to_find);
		exit(1);
	}

	ino_t get_inode(char *filename){
		struct stat info;
		if(stat(filename, &info) == -1){
			fprintf(stderr, "cannot stat");
			perror(NULL);
			exit(-1);
		}
		return info.st_ino;
	}
