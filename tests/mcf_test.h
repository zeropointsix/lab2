#ifndef MCF_TEST_H
#define MCF_TEST_H
#include "shared.h"

extern "C" {
#include "common.h"
}

TEST(mcf_test, attheend) {
    FILE *outputFile;
    TRAVIS ? outputFile = fopen("tests/output/output10.txt", "wb") : outputFile = fopen("../../lab2/tests/output/output10.txt", "wb");
    if (outputFile == NULL) {
        printf("Cannot open file for output. ");
        FAIL();
    }
    int oldstdOut = changeStream(outputFile);

    text txt = create_text();
    char inFile[MAXLINE];
    TRAVIS ? strncpy(inFile, "tests/input/input10.txt", MAXLINE) : strncpy(inFile, "../../lab2/tests/input/input10.txt", MAXLINE);
    load(txt, inFile);

    mcf(txt);
    show(txt);

    returnStream(outputFile, oldstdOut);

    FILE *expectedData;
    TRAVIS ? expectedData = fopen("tests/expected/expected10.txt", "r") : expectedData = fopen("../../lab2/tests/expected/expected10.txt", "r");
    FILE *outputData;
    TRAVIS ? outputData = fopen("tests/output/output10.txt", "r") : outputData = fopen("../../lab2/tests/output/output10.txt", "r");

    if (executeTest(expectedData, outputData) == 1) {
        SUCCEED();
    } else {
        FAIL();
    }
}

TEST(mcf_test, not_attheend) {
    FILE *outputFile;
    TRAVIS ? outputFile = fopen("tests/output/output11.txt", "wb") : outputFile = fopen("../../lab2/tests/output/output11.txt", "wb");
    if (outputFile == NULL) {
        printf("Cannot open file for output. ");
        FAIL();
    }
    int oldstdOut = changeStream(outputFile);

    text txt = create_text();
    char inFile[MAXLINE];
    TRAVIS ? strncpy(inFile, "tests/input/input11.txt", MAXLINE) : strncpy(inFile, "../../lab2/tests/input/input11.txt", MAXLINE);
    load(txt, inFile);

    mwcrsr(txt, 1, 4);
    mcf(txt);
    mcf(txt);
    mcf(txt);
    show(txt);

    returnStream(outputFile, oldstdOut);

    FILE *expectedData;
    TRAVIS ? expectedData = fopen("tests/expected/expected11.txt", "r") : expectedData = fopen("../../lab2/tests/expected/expected11.txt", "r");
    FILE *outputData;
    TRAVIS ? outputData = fopen("tests/output/output11.txt", "r") : outputData = fopen("../../lab2/tests/output/output11.txt", "r");

    if (executeTest(expectedData, outputData) == 1) {
        SUCCEED();
    } else {
        FAIL();
    }
}

TEST(mcf_test, next_line) {
    FILE *outputFile;
    TRAVIS ? outputFile = fopen("tests/output/output12.txt", "wb") : outputFile = fopen("../../lab2/tests/output/output12.txt", "wb");
    if (outputFile == NULL) {
        printf("Cannot open file for output. ");
        FAIL();
    }
    //int oldstdOut = changeStream(outputFile);

    text txt = create_text();
    char inFile[MAXLINE];
    TRAVIS ? strncpy(inFile, "tests/input/input12.txt", MAXLINE) : strncpy(inFile, "../../lab2/tests/input/input12.txt", MAXLINE);
    load(txt, inFile);
    
    mwcrsr(txt, 1, 9);
    mcf(txt);
    mcf(txt);
    mcf(txt);
    show(txt);

    //returnStream(outputFile, oldstdOut);
/*
    FILE *expectedData;
    TRAVIS ? expectedData = fopen("tests/expected/expected12.txt", "r") : expectedData = fopen("../../lab2/tests/expected/expected12.txt", "r");
    FILE *outputData;
    TRAVIS ? outputData = fopen("tests/output/output12.txt", "r") : outputData = fopen("../../lab2/tests/output/output12.txt", "r");

    if (executeTest(expectedData, outputData) == 1) {
        SUCCEED();
    } else {
        FAIL();
    }
 */
}

#endif // MCF_TEST_H
