#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void wakeup(int signum){
	printf("Alarm received from kernel\n");
	alarm(3);
}

int main(){
	signal(SIGALRM, wakeup);
	printf("About to sleep for 4 seconds\n");
	alarm(3);

	while(1)
		pause();

	printf("Morning so soon?\n");
	return 0;
}