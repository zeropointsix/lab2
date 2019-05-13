#ifndef SHOWUPPER_TEST_H
#define SHOWUPPER_TEST_H
#include "shared.h"

extern "C" {
#include "common.h"
}


TEST(shownum_test, emptyfile) {
    FILE *outputFile;
    TRAVIS ? outputFile = fopen("tests/output/output1.txt", "wb") : outputFile = fopen("../../lab2/tests/output/output1.txt", "wb");
    if (outputFile == NULL) {
        printf("Cannot open file for output");
        FAIL();
    }
    int oldstdOut = changeStream(outputFile);
    
    text txt = create_text();
    char inFile[MAXLINE];
    TRAVIS ? strncpy(inFile, "tests/input/empty.txt", MAXLINE) : strncpy(inFile, "../../lab2/tests/input/empty.txt", MAXLINE);
    load(txt, inFile);
    
    shownum(txt);
    
    fclose(outputFile);
    returnStream(outputFile, oldstdOut);
    
    FILE *expectedData;
    TRAVIS ? expectedData = fopen("tests/expected/shownum_test1.txt", "r") : expectedData = fopen("../../lab2/tests/expected/shownum_test1.txt", "r");
    FILE *outputData;
    TRAVIS ? outputData = fopen("tests/output/output1.txt", "r") : outputData = fopen("../../lab2/tests/output/output1.txt", "r");

    if (executeTest(expectedData, outputData) == 1) {
        SUCCEED();
    } else {
        FAIL();
    }
    fclose(expectedData);
    fclose(outputData);
}

#endif // SHOWUPPER_TEST_H
