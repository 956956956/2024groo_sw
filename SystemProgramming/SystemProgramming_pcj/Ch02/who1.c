#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <string.h>

void show_info(struct utmp *ut_buf_p) {
	printf("%-8.8s", ut_buf_p->ut_user);
	printf(" ");
	printf("%-8.8s", ut_buf_p->ut_line);
	printf(" ");

	long sec = (long)ut_buf_p->ut_tv.tv_sec;
	char *ctime_str = ctime(&sec);
	ctime_str[strlen(ctime_str) - 1] = '\0';
	printf("%s ", ctime_str);
	printf("(%s)\n",ut_buf_p->ut_host);
}

int main() {
	struct utmp current_record;
	int utmpfd;
	size_t rec_len = sizeof(struct utmp);

	if ((utmpfd = open("/var/run/utmp", O_RDONLY)) == -1) {
		perror(UTMP_FILE);
		exit(-1);
	}

	while ((read(utmpfd, &current_record, rec_len) == rec_len)) {
		show_info(&current_record);
	}

	close(utmpfd);
	return 0;
}