#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#define BUFFERSIZE 1024
int main(){
    int source_file,dest_file;
    ssize_t bytesRead,bytesWritten;
    char buffer[BUFFERSIZE];

    source_file = open("source.txt",O_RDONLY);
    if(source_file<0){
        perror("Error while opening source file");
        exit(1);
    }

    dest_file = open("dest.txt",O_WRONLY|O_CREAT|O_TRUNC ,0644);

    if(dest_file<0){
        perror("Error while opening destination file");
        close(source_file);
        exit(1);
    }

    while(bytesRead = read(source_file,buffer,BUFFERSIZE)){
        bytesWritten = write(dest_file,buffer,bytesRead);

        if(bytesRead != bytesWritten){
            perror("Does not copied successfully");
            close(source_file);
            close(dest_file);
            exit(1);
        }
    }

    if(bytesRead<0){
        perror("Error reading from source file ");
    }
    close(source_file);
    close(dest_file);
    exit(1);

    printf("Copied Successfully");
}
