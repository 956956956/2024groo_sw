#include <stdio.h>
#include <sys/stat.h>

void show_stat_info(char *fname, struct stat *buf) {
	printf("    mode: %o\n", buf->st_mode);
	printf("    mode: 0x%x\n", buf->st_mode);
	printf("   links: %ld\n", buf->st_nlink);
	printf("    user: %d\n", buf->st_uid);
	printf("   group: %d\n", buf->st_gid);
	printf("    size: %ld\n", buf->st_size);
	printf("modetime: %ld\n", buf->st_mtime);
	printf("    name: %s\n", fname);
}

int main(int ac, char *av[]) {
	struct stat buf;
	if (ac > 1) {
		if (stat(av[1], &buf) != -1) {
			show_stat_info(av[1], &buf);
		}
	} else {
		return -1;
	}

	return 0;
}