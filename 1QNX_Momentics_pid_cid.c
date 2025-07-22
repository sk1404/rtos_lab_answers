#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> // for fork(), getpid(), getppid(), sleep ()
#include <sys/wait.h> // for wait()
int main() {
pid_t pid=fork();
if (pid < 0) {
perror("fork failed");
return 1;
}
else if (pid == 0){
// Child process
printf("Child PID: %d\n", getpid());
printf("Parent PID from child: %d\n", getppid());
sleep (10); // Child works for 10 seconds
printf("Child done\n");
}
else {
// Parent process
printf("Parent PID: %d\n", getpid());
printf("Child PID from parent: %d\n", pid);
sleep (5); // Parent waits 5 seconds before terminating
printf("Parent exiting after 5 seconds \n");
// Parent exits here, child is still running
// Optionally, wait for child before exiting (commented out to demonstrate orphan)
}
return 0;
}
