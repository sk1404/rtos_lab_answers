#include <stdio.h>
#include <unistd.h> // fork, sleep, getpid, getppid
#include <sys/types.h> // pid_t
#include <stdlib.h> // exit
#include <sys/wait.h> // wait
#define NUM_CHILDREN 3
int main() {
pid_t pid;
int i;
printf("Parent process started. PID: %d\n", getpid());
for (i=0; i< NUM_CHILDREN; i++) {
pid= fork();
if (pid < 0) {
perror("fork failed");
exit(1);
}
else if (pid == 0) {
// This is child process
printf(" Child %d created.\n", i + 1);
printf(" Child PID: %d\n", getpid());
printf(" Parent PID (from child): %d\n", getppid());
sleep (10);
// Simulate work
printf(" Child %d (PID: %d) exiting after work\n", i + 1,getpid());
exit(0);
}
else {
 printf("parent created chid %d with pid :%d\n",i+1,pid);
}
// Parent process continues loop to create more children
printf(" Parent created child %d with PID:%d\n", i + 1, pid);
 // Parent process sleeps and exits
 sleep (5);
 printf(" Parent (PID: %d) exiting after 5 seconds\n", getpid());
 // Parent exits without waiting for children
}
return 0;
}
