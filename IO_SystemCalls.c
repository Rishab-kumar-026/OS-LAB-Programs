#include <stdio.h>
 #include <stdlib.h>
 #include <fcntl.h>
 #include <unistd.h>
 #define BUFFER_SIZE 1024
 int main() {
 int sourceFile, destFile;
 ssize_t bytesRead, bytesWritten;
 char buffer[BUFFER_SIZE];
// Open the source file for reading
 sourceFile = open("source.txt", O_RDONLY);
 if (sourceFile < 0) {
 perror("Error opening source file");
 exit(1);
 }
 // Open the destination file for writing (create if it doesn't exist)
 destFile = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
 if (destFile < 0) {
 perror("Error opening destination file");
 close(sourceFile);
 exit(1);
 }
 // Read from the source file and write to the destination file
 while ((bytesRead = read(sourceFile, buffer, BUFFER_SIZE)) > 0) {
 bytesWritten = write(destFile, buffer, bytesRead);
 if (bytesWritten != bytesRead) {
 perror("Error writing to destination file");
 close(sourceFile);
 close(destFile);
 exit(1);
 }
 }
 if (bytesRead < 0) {
 perror("Error reading from source file");
 }
 // Close both files
 close(sourceFile);
 close(destFile);
 printf("File copied successfully.\n");
 return 0;
 }