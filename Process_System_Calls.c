 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 int main() {
 pid_t pid;
 // Create a new process
 pid = fork();
 if (pid < 0) {
 // Error occurred
 printf("Fork failed!\n");
 exit(1);
 } else if (pid == 0) {
 // Child process
 printf("This is the child process.\n");
 printf("Child Process ID: %d\n", getpid());
 printf("Parent Process ID: %d\n", getppid());
 } else {
 // Parent process
 printf("This is the parent process.\n");
 printf("Parent Process ID: %d\n", getpid());
 printf("Child Process ID: %d\n", pid);
 }
 return 0;
 }