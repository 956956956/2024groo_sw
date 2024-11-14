#include "main.h"

void print_string(char *msg){
	int len = strlen(msg);
	printf("len: %d, string: %s\n", len, msg);
	for(int i = 0; i < len; i++)
		printf("%c ", msg[i]);
	printf("\n");
}