#include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <string.h>
#define BUFFER_SIZE 100
 int main() {
 int pipefd[2];
 pid_t pid;
 char writeMessage[] = "Hello from the parent process!";
 char readMessage[BUFFER_SIZE];
 // Create a pipe
 if (pipe(pipefd) ==-1) {
 perror("Pipe failed");
 exit(1);
 }
 // Create a child process
 pid = fork();
 if (pid < 0) {
 // Fork failed
 perror("Fork failed");
 exit(1);
 } else if (pid == 0) {
 // Child process
 close(pipefd[1]); // Close the write end of the pipe
 // Read message from the pipe
 read(pipefd[0], readMessage, BUFFER_SIZE);
 printf("Child process received message: %s\n", readMessage);
 close(pipefd[0]); // Close the read end of the pipe
 } else {
 // Parent process
 close(pipefd[0]); // Close the read end of the pipe
 // Write message to the pipe
 write(pipefd[1], writeMessage, strlen(writeMessage) + 1);
 printf("Parent process sent message: %s\n", writeMessage);
 close(pipefd[1]); // Close the write end of the pipe
 }
 return 0;
 }