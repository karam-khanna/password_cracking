#include <stdio.h>
#include <iostream>
#include <stdlib.h>

void searchForMatch(const char* filename, const char* query);

int main(int argc, char const *argv[])
{
    /* code */
    printf("hello there \n");
    searchForMatch("MainEnglishDictionary_ProbWL.txt", "0aperitivo");

    return 0;

}

void searchForMatch(const char* filename, const char* query) {
    long length;
    char* buffer = 0;
    FILE *f = fopen(filename, "rb");

    if (f) {
        fseek(f,0,SEEK_END); //sets our seek to the end of the stream
        length = ftell(f); //gets distance from stream pointer to start of file, aka gets length of file
        fseek(f,0, SEEK_SET); //points stream pointer back at start 
        buffer = (char *) malloc(length);
        if (buffer) {
            fread(buffer, 1, length ,f); //assumes char is size 1
        }
        fclose (f);
    }

    int64_t offset = 0;
    char str[100];
    int lengthOfString = 1;
    char * endPoint;



    while ( lengthOfString > 0) {
        // get string
        buffer+= offset;

        endPoint = (char *) memchr(buffer, '\n', 180);
        lengthOfString = endPoint - buffer;
        if (lengthOfString < 0) {
            printf("reached end of input");
            return;
        }

        offset = lengthOfString+1;


        memcpy(str, buffer, lengthOfString);
        str[lengthOfString] = '\0';
        


        printf("current str: %s\n", (char*) str);

    }



}


