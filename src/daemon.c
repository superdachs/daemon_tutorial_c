#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

int process(void) {
    // do some stuff here
}

int main(void) {
    
    pid_t pid, sid;

    printf("starting with pid %ld\n", (long) getpid());

    pid = fork();
    long pidnum = (long) pid;
    if(pid < 0) {
        exit(EXIT_FAILURE);
    }

    if(pid > 0) {
        exit(EXIT_SUCCESS);
    }

    printf("forked with pid %ld\n", pidnum);
    


    umask(0);

    sid = setsid();
    if(sid < 0) {
        exit(EXIT_FAILURE);
    }

    if(chdir("/") < 0) {
        exit(EXIT_FAILURE);
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    while(1) {
        sleep(1);

    }

    exit(EXIT_SUCCESS);
}

