#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//You may also add more include directives as well.

// THIS VALUE CANNOT BE CHANGED.
// You should use this value when creating your buffer.
// And also to limit the amount of bytes each read CAN do.
#define BUFF_MAX 21
// ABOVE VALUE CANNOT BE CHANGED //
#define NAME "Tsun Ming Lee"

int main(int argc, char const *argv[])
{
    
    char oldFile[100]; //file name
    char newFile[100]; //file name
    
    //create buff for copy
    char copyBuff[BUFF_MAX];
    
    printf("Welcome to the File Copy Program by %s!\n",NAME);
    
    printf("Enter the name of the file to copy from:");
    scanf("%s", oldFile);
    
    printf("Enter the name of the file to copy to:");
    scanf("%s", newFile);
    
    //Open the input file, if file doesn't exist
    int fileOld = open(oldFile, O_RDONLY); //O_RDONLY mean read only
    
    if (fileOld < 0)
    {
        perror("Opening file doesn't exists.\n");
        return -1;
    }
    
    //Open the input file, if file exists
    int fileNew = open(newFile, O_CREAT | O_WRONLY);
    /*
        O_CREAT, create file if it doesn't exists
        O_WRONLY, write only
    */
    
    if (fileNew < 0)
    {
        perror("File failed to create");
        return -1;
    }

    //Loop, read from input file
    ssize_t numOfBytesRead;
    ssize_t numOfBytesWrite;
    int totalBytes = 0;
    
    while ((numOfBytesRead = read(fileOld, copyBuff, BUFF_MAX)) > 0)
    {
        //totalBytes = numOfBytes + totalBytes;
        numOfBytesWrite = write(fileNew, copyBuff, numOfBytesRead); //here use numOfBytes cuz of line 59, numberOfBytes = read(...), that mean it read fileOld(Max 21 each times), in fact, we don't know how many we need to read, so "write" everytime got from what the while loop return.
        totalBytes += numOfBytesWrite;
    } //when the while loop stop, mean read fail cuz no more btyes to read
    
    
    
    
    printf("File Copy Successful, %d bytes copied.\n", totalBytes);
    
    //Close files
    close(fileOld);
    close(fileNew);
    
    return 0;
}
