#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(){
	int count = 0;
	while(1){
		printf("PID: %i\n", getpid());
		printf("Seconds in process: %i\n", count);
		sleep(2);
		count = +2;
	}
	return 0;
}