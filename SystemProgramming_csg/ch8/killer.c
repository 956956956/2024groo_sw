#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(){
	int sig;
	int id;
	while(1) {
		printf("Enter PID: ");
		scanf("%d", &id);
		printf("Enter signal: ");
		scanf("%d", &sig);
		printf("Send signal %d to %d\n", sig, id);

		kill(id, sig);
	}
	return 0;
}