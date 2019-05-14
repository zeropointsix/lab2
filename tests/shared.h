#ifndef SHARED_H
#define SHARED_H
#include <gtest/gtest.h>
#include <sys/io.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#define TRAVIS 1

extern "C" {
#include "common.h"
}

int changeStream(FILE* file) {
    int oldstdOut = dup(1);
    close(1);
    dup2(fileno(file), 1);

    return oldstdOut;
}

void returnStream(FILE* file, int oldstdOut) {
    fflush(stdout);
    fclose(file);
    dup2(oldstdOut, 1);
}

int executeTest(FILE* expectedData, FILE* outputData) {
    if (expectedData == NULL) {
        printf("Cannot open expected file \n");
        return 0;
    }
    if (outputData == NULL) {
        printf("Cannot open output file \n");
        return 0;
    }

    char expectedLine[MAXLINE];
    char outputLine[MAXLINE];

    while ((fgets(expectedLine, MAXLINE, expectedData) != NULL) | (fgets(outputLine, MAXLINE, outputData) != NULL)) {
        int i=0;
        printf("Expected line %zd: \"%s\", output line %zd: \"%s\" \n", strlen(expectedLine), expectedLine,  strlen(outputLine), outputLine);
        for(i=0;((expectedLine[i]!='\0')&&(expectedLine[i]!='\n')&&(outputLine[i]!='\0')&&(outputLine[i]!='\n'));i++){
            if(expectedLine[i]!=outputLine[i]) {
                fclose(expectedData); fclose(outputData);
                return 0;
            }
        }
        /*
        expectedLine[strlen(expectedLine) - 1] = '\0';
        outputLine[strlen(outputLine) - 1] = '\0';
        printf("%zd -- %zd \n", strlen(expectedLine), strlen(outputLine));
        printf("Expected line: \"%s\", output line: \"%s\" \n", expectedLine, outputLine);
        if (strcmp(expectedLine, outputLine) != 0) return 0;*/
    }
    fclose(expectedData); fclose(outputData);
    return 1;
}

#endif // SHARED_H
