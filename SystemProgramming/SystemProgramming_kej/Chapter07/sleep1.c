#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void wakeup(int signum) {
	printf("Alarm received from kernel\n");
}

int main() {
	signal(SIGALRM, wakeup);
	printf("About to sleep for 4 seconds\n");
	alarm(4);
	pause();
	// instead of
	// while(1)
	// 		pause();
	printf("Morning so soon?\n");
	return 0;
}