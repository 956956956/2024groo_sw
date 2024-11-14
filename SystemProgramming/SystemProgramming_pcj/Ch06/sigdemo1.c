#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void f(int signum) {
    printf("OUCH!\n");
}

int main() {
    signal(SIGINT, f);

    for (int i = 0; i < 5; i++) {
        printf("hello\n");
        sleep(1);
    }

    return 0;
}