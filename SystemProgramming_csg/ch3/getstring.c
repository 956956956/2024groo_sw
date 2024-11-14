#include "main.h"

void get_string(char *msg){
	int len = 0;
	printf("Type string: ");
	fgets(msg, BUF_SIZE, stdin);
	len = strlen(msg);
	msg[len-1] = 0;
}
