#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

void count_down(int signum) {
	static int num = 10;
	printf("%d..", num--);
	fflush(stdout);

	if (num<0) {
		printf("DONE!\n");
		exit(EXIT_SUCCESS);
	}
}

int set_ticker(int n_msecs) {
	struct itimerval new_timeset;
	long n_secs, n_usecs;

	n_secs = (long)(n_msecs / 1000);
	n_usecs = (long)(n_msecs % 1000) * 1000L;

	new_timeset.it_value.tv_sec = n_secs;
	new_timeset.it_value.tv_usec = n_usecs;

	new_timeset.it_interval.tv_sec = n_secs;
	new_timeset.it_interval.tv_usec = n_usecs;

	return setitimer(ITIMER_REAL, &new_timeset, NULL);
}

int main() {
	signal(SIGALRM, count_down);
	if (set_ticker(500) == -1) {
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	else {
		while(1)
			pause();
	}
	return 0;
}