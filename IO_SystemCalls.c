#include<stdio.h>
#include<stdlib.h>//used for functions like exit()
#include<fcntl.h>
#include<unistd.h>//both are used for read,write,close,open files
#define BUFFER_SIZE 1024// determines the number of bytes read from the source file at a time.
int main(){
    int sourceFile,destinationFile;
    ssize_t bytesRead ,bytesWritten;//determines how much data is read and written in/from source&destination files
    char buffer[BUFFER_SIZE];
    
    sourceFile = open("source.txt",O_RDONLY);
    if(sourceFile<0){
        perror("Error while opening source File");
        exit(1);
    }
    
    destinationFile = open("destination.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);
    //0644 making the file readable and writable by the owner, and readable by others.
    
    if(destinationFile<0){
        perror("Error while opening Destination File");
        close(sourceFile);
        exit(1);
    }
    
    while(bytesRead = read(sourceFile,buffer,BUFFER_SIZE)){
        bytesWritten = write(destinationFile,buffer,bytesRead);
    if(bytesRead != bytesWritten){
        perror("Doesn't copied successfully");
    }
    close(sourceFile);
    close(destinationFile);
    exit(1);
    }

if(bytesRead < 0){ //checks whether source file is empty or not
    perror("Error reading from source File");
}
close(sourceFile);
close(destinationFile);

printf("Successfully Copied from Source File and Written in Destination File");
}